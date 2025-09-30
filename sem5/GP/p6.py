import pygame
import sys

pygame.init()

WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bouncing Sprite with Gravity")
clock = pygame.time.Clock()


ball_radius = 40
ball_surface = pygame.Surface((ball_radius * 2, ball_radius * 2), pygame.SRCALPHA)
pygame.draw.circle(ball_surface, (0, 0, 255), (ball_radius, ball_radius), ball_radius)
walk_frames = [ball_surface]

player_x = 100
player_y = 100
player_speed_x = 5
player_width, player_height = walk_frames[0].get_size()

velocity_y = 0
gravity = 0.6
bounce_strength = -20
damping = 0.9

player_index = 0
frame_delay = 8
frame_counter = 0
moving = False
running = True

while running:
    screen.fill((255, 255, 255))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    keys = pygame.key.get_pressed()
    moving = False

    if keys[pygame.K_LEFT]:
        player_x -= player_speed_x
        moving = True
    if keys[pygame.K_RIGHT]:
        player_x += player_speed_x
        moving = True

    if player_x < 0:
        player_x = 0
    if player_x + player_width > WIDTH:
        player_x = WIDTH - player_width

    velocity_y += gravity
    player_y += velocity_y

    if player_y <= 0:
        player_y = 0
        velocity_y = -velocity_y * damping

    if player_y + player_height >= HEIGHT:
        player_y = HEIGHT - player_height
        velocity_y = bounce_strength

    if moving:
        frame_counter += 1
        if frame_counter >= frame_delay:
            player_index = (player_index + 1) % len(walk_frames)
            frame_counter = 0
    else:
        player_index = 0

    screen.blit(walk_frames[player_index], (player_x, player_y))

    pygame.display.flip()
    clock.tick(120)

pygame.quit()
sys.exit()
