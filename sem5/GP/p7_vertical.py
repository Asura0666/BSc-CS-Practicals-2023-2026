import pygame
import sys
import math

pygame.init()

WIDTH, HEIGHT = 800, 800
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Vertical Back-and-Forth with Squeeze")

TURQUOISE = (255, 20, 147)
BLUE = (173, 216, 230)

radius = 40
x = WIDTH / 2  # Keep x fixed in the center
y = radius
vel = 6

dir_y = 1  # Only vertical direction

clock = pygame.time.Clock()

center_y = HEIGHT / 2
max_dist = center_y - radius  # Max distance from center (top or bottom)

running = True
while running:
    clock.tick(120)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Move vertically
    y += dir_y * vel

    # Bounce off top and bottom
    if y + radius >= HEIGHT:
        dir_y = -1
    if y - radius <= 0:
        dir_y = 1

    # Squeeze effect based on distance from center
    dist_to_center = abs(center_y - y)
    norm_dist = min(dist_to_center / max_dist, 1)
    squeeze = 0.2 + 0.4 * norm_dist
    vert_radius = radius * squeeze
    horiz_radius = radius * squeeze

    screen.fill(BLUE)

    ellipse_rect = pygame.Rect(0, 0, horiz_radius * 2, vert_radius * 2)
    ellipse_rect.center = (int(x), int(y))

    pygame.draw.ellipse(screen, TURQUOISE, ellipse_rect)

    pygame.display.flip()

pygame.quit()
sys.exit()
