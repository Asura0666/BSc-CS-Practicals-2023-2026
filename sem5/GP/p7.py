import pygame
import sys
import math

pygame.init()

WIDTH, HEIGHT = 800, 800
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Diagonal Back-and-Forth with Squeeze")

TURQOUISE = (255, 20, 147)
BLUE = (173, 216, 230)

radius = 40
x, y = radius, radius
vel = 6


dir_x, dir_y = 1, 1

clock = pygame.time.Clock()

center_x, center_y = WIDTH / 2, HEIGHT / 2
max_dist = math.hypot(center_x - radius, center_y - radius)

running = True
while running:
    clock.tick(120)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    x += dir_x * vel
    y += dir_y * vel

    if x + radius >= WIDTH and y + radius >= HEIGHT:
        dir_x, dir_y = -1, -1

    if x - radius <= 0 and y - radius <= 0:
        dir_x, dir_y = 1, 1

    dist_to_center = math.hypot(center_x - x, center_y - y)
    norm_dist = min(dist_to_center / max_dist, 1)

    squeeze = 0.2 + 0.4 * norm_dist
    vert_radius = radius * squeeze
    horiz_radius = radius * squeeze

    screen.fill(BLUE)

    ellipse_rect = pygame.Rect(0, 0, horiz_radius * 2, vert_radius * 2)
    ellipse_rect.center = (int(x), int(y))

    pygame.draw.ellipse(screen, TURQOUISE, ellipse_rect)

    pygame.display.flip()

pygame.quit()
sys.exit()
