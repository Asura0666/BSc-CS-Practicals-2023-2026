import pygame
import math
import sys

pygame.init()

WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pygame Window with Transformed Shapes")

WHITE = (255, 255, 255)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

clock = pygame.time.Clock()

rect_w, rect_h = 100, 60
original_rect = pygame.Surface((rect_w, rect_h), pygame.SRCALPHA)
original_rect.fill(RED)
angle = 0
scale = 1.0
rect_center = (200, 200)

circle_pos = [100, 400]
circle_radius = 40
circle_speed = 3

def draw_triangle(surface, center, size, angle, color):
    x, y = center
    points = []
    for i in range(3):
        theta = math.radians(angle + i * 120)
        px = x + size * math.cos(theta)
        py = y + size * math.sin(theta)
        points.append((px, py))
    pygame.draw.polygon(surface, color, points)

triangle_angle = 0

running = True
while running:
    screen.fill(WHITE)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    scaled = pygame.transform.scale(original_rect, (int(rect_w * scale), int(rect_h * scale)))
    rotated = pygame.transform.rotate(scaled, angle)
    rect = rotated.get_rect(center=rect_center)
    screen.blit(rotated, rect)

    angle += 1
    scale += 0.01
    if scale > 2:
        scale = 1.0

    pygame.draw.circle(screen, BLUE, (int(circle_pos[0]), int(circle_pos[1])), circle_radius)
    circle_pos[0] += circle_speed
    if circle_pos[0] > WIDTH - circle_radius or circle_pos[0] < circle_radius:
        circle_speed *= -1

    draw_triangle(screen, (600, 400), 60, triangle_angle, GREEN)
    triangle_angle += 2

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
