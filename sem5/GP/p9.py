import pygame
import random

pygame.init()

# Screen setup
WIDTH, HEIGHT = 900, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bucket Star Catcher (Shapes Version)")

clock = pygame.time.Clock()
FPS = 60

# Colors
BLACK = (0, 0, 0)
BG_COLOR = (255, 245, 230)
BUCKET_COLOR = (0, 120, 255)  # Blue
STAR_COLOR = (255, 215, 0)  # Yellow (gold)
BOMB_COLOR = (200, 0, 0)  # Red

# Fonts
font = pygame.font.SysFont("Arial", 28)
big_font = pygame.font.SysFont("Arial", 48)


# Game variables (global so reset_game can update them)
def reset_game():
    global bucket, bucket_speed, stars, bombs, fall_speed, score, level, spawn_timer, game_over

    # Bucket setup
    bucket = pygame.Rect(WIDTH // 2, HEIGHT - 70, 80, 60)
    bucket_speed = 8

    # Objects
    stars = []
    bombs = []

    # Game state
    fall_speed = 4
    score = 0
    level = 1
    spawn_timer = 0
    game_over = False


# Required scores for each level
required_scores = {1: 10, 2: 20, 3: 30}


def spawn_star():
    x = random.randint(0, WIDTH - 30)
    return pygame.Rect(x, -30, 30, 30)


def spawn_bomb():
    x = random.randint(0, WIDTH - 30)
    return pygame.Rect(x, -30, 30, 30)


def draw():
    screen.fill(BG_COLOR)

    # Draw bucket
    pygame.draw.rect(screen, BUCKET_COLOR, bucket, border_radius=10)

    # Draw stars
    for star in stars:
        pygame.draw.circle(screen, STAR_COLOR, star.center, star.width // 2)

    # Draw bombs
    for bomb in bombs:
        pygame.draw.rect(screen, BOMB_COLOR, bomb, border_radius=5)
        pygame.draw.line(screen, BLACK, bomb.topleft, bomb.bottomright, 2)
        pygame.draw.line(screen, BLACK, bomb.topright, bomb.bottomleft, 2)

    # Score + Level
    score_text = font.render(f"Score: {score}", True, BLACK)
    level_text = font.render(f"Level: {level}", True, BLACK)
    screen.blit(score_text, (10, 10))
    screen.blit(level_text, (10, 40))

    pygame.display.flip()


def show_message(title, subtitle, wait_time=2000):
    screen.fill(BG_COLOR)
    title_surf = big_font.render(title, True, BLACK)
    subtitle_surf = font.render(subtitle, True, BLACK)

    screen.blit(
        title_surf, (WIDTH // 2 - title_surf.get_width() // 2, HEIGHT // 2 - 50)
    )
    screen.blit(
        subtitle_surf, (WIDTH // 2 - subtitle_surf.get_width() // 2, HEIGHT // 2 + 10)
    )

    pygame.display.flip()
    pygame.time.wait(wait_time)


# Start first game
reset_game()
running = True

while running:
    clock.tick(FPS)
    spawn_timer += 1

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not game_over:
        # Move bucket
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and bucket.left > 0:
            bucket.x -= bucket_speed
        if keys[pygame.K_RIGHT] and bucket.right < WIDTH:
            bucket.x += bucket_speed

        # Spawn stars
        if spawn_timer % 30 == 0:
            stars.append(spawn_star())

        # Spawn bombs (only from level 2+)
        if level >= 2 and spawn_timer % 50 == 0:
            bombs.append(spawn_bomb())

        # Move stars
        for star in stars[:]:
            star.y += fall_speed
            if star.colliderect(bucket):
                stars.remove(star)
                score += 1
            elif star.y > HEIGHT:
                stars.remove(star)

        # Move bombs
        for bomb in bombs[:]:
            bomb.y += fall_speed
            if bomb.colliderect(bucket):
                game_over = True
                show_message(
                    "Game Over", "You caught a bomb! Press R to restart or Q to quit."
                )
            elif bomb.y > HEIGHT:
                bombs.remove(bomb)

        # Level progression
        if not game_over and score >= required_scores[level]:
            if level < 3:
                level += 1
                stars.clear()
                bombs.clear()
                show_message(
                    f"Level {level}", f"Collect {required_scores[level]} stars!"
                )
            else:
                show_message("Congratulations!", "You completed all levels!")
                reset_game()

        draw()

    else:
        # Restart/Quit handling after Game Over
        keys = pygame.key.get_pressed()
        if keys[pygame.K_r]:
            reset_game()
        elif keys[pygame.K_q]:
            running = False

pygame.quit()
