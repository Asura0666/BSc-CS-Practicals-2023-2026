import pygame
import math
import os
import random

pygame.init()

WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("shape based coin collector pygame")

clock = pygame.time.Clock()
FPS = 120

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
BG_COLOR = (255, 245, 230)
PLAYER_COLOR = (0, 150, 255)
ENEMY_COLOR = (255, 60, 60)
COIN_COLOR = (255, 215, 0)

font = pygame.font.SysFont("Times new roman", 28)
large_font = pygame.font.SysFont("Times new roman", 48)

coin_sound = pygame.mixer.Sound("./coin_collect.mp3")
game_over_sound = pygame.mixer.Sound("./game_over.mp3")


def reset_game():
    global player, enemy, coins, player_speed, enemy_speed, player_score, game_over
    player = pygame.Rect(100, 100, 50, 50)
    enemy = pygame.Rect(700, 500, 40, 40)
    coins = []

    for _ in range(10):
        x = random.randint(50, WIDTH - 50)
        y = random.randint(50, HEIGHT - 50)
        coins.append(pygame.Rect(x, y, 20, 20))

    player_speed = 6
    enemy_speed = 2

    player_score = 0
    game_over = False


def move_enemy(enemy, target):
    dx = target.centerx - enemy.centerx
    dy = target.centery - enemy.centery
    dist = math.hypot(dx, dy)

    if dist != 0:
        dx, dy = dx / dist, dy / dist
        enemy.x += dx * enemy_speed
        enemy.y += dy * enemy_speed


def draw():
    screen.fill(BG_COLOR)

    for coin in coins:
        pygame.draw.circle(screen, COIN_COLOR, coin.center, coin.width // 2)

    pygame.draw.rect(screen, PLAYER_COLOR, player)

    pygame.draw.rect(screen, ENEMY_COLOR, enemy)

    score_text = font.render(f"Player Score: {player_score}", True, BLACK)
    screen.blit(score_text, (10, 10))

    pygame.display.flip()


def show_game_over(reason):
    screen.fill(BG_COLOR)
    over_text = large_font.render("Game Over", True, (200, 0, 0))
    reason_text = font.render(reason, True, BLACK)
    restart_text = font.render("Press R to restart OR Q to Quit", True, (200, 0, 0))

    screen.blit(over_text, (WIDTH // 2 - over_text.get_width() // 2, HEIGHT // 2 - 50))
    screen.blit(
        reason_text, (WIDTH // 2 - reason_text.get_width() // 2, HEIGHT // 2 + 10)
    )
    screen.blit(
        restart_text, (WIDTH // 2 - restart_text.get_width() // 2, HEIGHT // 2 + 40)
    )
    pygame.display.flip()
    pygame.time.wait(3000)


reset_game()

running = True

while running:
    clock.tick(FPS)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        if game_over and event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                reset_game()
            elif event.key == pygame.K_q:
                running = False

    if not game_over:

        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            player.x -= player_speed
        if keys[pygame.K_RIGHT]:
            player.x += player_speed
        if keys[pygame.K_UP]:
            player.y -= player_speed
        if keys[pygame.K_DOWN]:
            player.y += player_speed

        player.x = max(0, min(WIDTH - player.width, player.x))
        player.y = max(0, min(HEIGHT - player.height, player.y))

        move_enemy(enemy, player)

        if player.colliderect(enemy):
            game_over_sound.play()
            game_over = True
            show_game_over("Enemy Caught You!")
            continue

        for coin in coins[:]:
            if player.colliderect(coin):
                coins.remove(coin)
                player_score += 1
                coin_sound.play()

        while len(coins) < 10:
            x = random.randint(50, WIDTH - 50)
            y = random.randint(50, HEIGHT - 50)
            coins.append(pygame.Rect(x, y, 20, 20))

        draw()


pygame.quit()
