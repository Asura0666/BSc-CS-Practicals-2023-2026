import pygame
import sys

pygame.init()


WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Animated Spirite movement")

clock = pygame.time.Clock()


walk_frames = [
    pygame.image.load("./images/ball1.png").convert_alpha(),
    pygame.image.load("./images/ball2.png").convert_alpha(),
    pygame.image.load("./images/ball3.png").convert_alpha(),
]


player_x = 100
player_y = 300
player_speed = 5
frame_index = 0
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
        player_x -= player_speed
        moving = True
    if keys[pygame.K_RIGHT]:
        player_x += player_speed
        moving = True
    if keys[pygame.K_UP]:
        player_y -= player_speed
        moving = True
    if keys[pygame.K_DOWN]:
        player_y += player_speed
        moving = True

    if moving:
        frame_counter += 1
        if frame_counter >= frame_delay:
            frame_index = (frame_index + 1) % len(walk_frames)
            frame_counter = 0
    else:
        frame_index = 0

    screen.blit(walk_frames[frame_index], (player_x, player_y))

    pygame.display.flip()
    clock.tick(60)
pygame.quit()
sys.exit()
