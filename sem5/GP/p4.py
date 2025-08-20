import pygame
import sys
import time

pygame.init()

width, height = 800, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Basic game loop with Restart + Key Display")
font = pygame.font.SysFont("Arial", 36)
clock = pygame.time.Clock()

game_running = True
game_over = False
message = ""
cursor_pos = ""
game_over_time = None  # track when game over happened

while game_running:
    screen.fill((255, 255, 255))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_running = False

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                game_running = False
            elif event.key == pygame.K_r:
                game_over = False
                message = ""
                game_over_time = None
            else:
                key_name = pygame.key.name(event.key)
                message = f"Key pressed: {key_name}"
                game_over = True
                game_over_time = time.time()

        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = event.pos
            if event.button == 1: 
                message = f"Left click at ({mouse_x}, {mouse_y})"
            elif event.button == 3:  
                message = f"Right click at ({mouse_x}, {mouse_y})"
            elif event.button == 2:  
                message = f"Middle click at ({mouse_x}, {mouse_y})"
            game_over = True
            game_over_time = time.time()

        elif event.type == pygame.MOUSEMOTION:
            mouse_x, mouse_y = event.pos
            cursor_pos = f"Cursor at ({mouse_x}, {mouse_y})"

    # Auto restart after 5 seconds
    if game_over and game_over_time:
        if time.time() - game_over_time >= 5:
            game_over = False
            message = ""
            game_over_time = None

    # Status message
    if not game_over:
        status_text = font.render("Game running - Press Q to quit, R to restart", True, (0, 0, 0))
    else:
        status_text = font.render("Game over - Auto restart in 5s (or press R)", True, (255, 0, 0))
    screen.blit(status_text, (50, height // 2 - 60))

    # Show last action
    if message:
        message_text = font.render(message, True, (0, 0, 255))
        screen.blit(message_text, (50, height // 2))

    # Show cursor position
    if cursor_pos:
        cursor_text = font.render(cursor_pos, True, (0, 150, 0))
        screen.blit(cursor_text, (50, height // 2 + 60))

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
