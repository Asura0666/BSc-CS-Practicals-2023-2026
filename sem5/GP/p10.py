import pygame
from collections import deque
import random

# ----- Constants -----
WIDTH, HEIGHT = 600, 600
ROWS, COLS = 15, 15
CELL_SIZE = WIDTH // COLS

WHITE = (240, 240, 240)
BLACK = (0, 0, 0)
BLUE = (50, 100, 255)  # Player
RED = (220, 50, 50)  # Enemy
GREEN = (50, 200, 50)  # Goal
GRAY = (255, 200, 200)  # Grid

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("BFS Enemy Chase (Shapes Version)")
clock = pygame.time.Clock()
font = pygame.font.SysFont("Arial", 24)

# ----- Grid -----
grid = [[0 for _ in range(COLS)] for _ in range(ROWS)]

# ----- Game state -----
player_pos = [0, 0]
enemy_pos = [ROWS - 1, COLS - 1]
goal_pos = [ROWS // 2, COLS // 2]

paused = False
game_over = False
you_win = False


# ----- BFS for enemy movement -----
def bfs(start, goal):
    start, goal = tuple(start), tuple(goal)
    q = deque([start])
    came_from = {start: None}
    while q:
        current = q.popleft()
        if current == goal:
            break
        r, c = current
        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] == 0:
                nxt = (nr, nc)
                if nxt not in came_from:
                    came_from[nxt] = current
                    q.append(nxt)
    # Reconstruct path
    path = []
    cur = goal
    while cur and cur in came_from:
        path.append(cur)
        cur = came_from[cur]
    path.reverse()
    return path


# ----- Reset game -----
def reset_game():
    global player_pos, enemy_pos, goal_pos, grid, game_over, you_win
    player_pos = [0, 0]
    enemy_pos = [ROWS - 1, COLS - 1]
    goal_pos = [ROWS // 2, COLS // 2]
    game_over = False
    you_win = False

    grid = [[0 for _ in range(COLS)] for _ in range(ROWS)]
    # Random walls
    for _ in range(50):
        r, c = random.randint(0, ROWS - 1), random.randint(0, COLS - 1)
        if (r, c) not in [tuple(player_pos), tuple(enemy_pos), tuple(goal_pos)]:
            grid[r][c] = 1


enemy_tick = 0
running = True
reset_game()

# ----- Game loop -----
while running:
    clock.tick(15)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_p:
                paused = not paused
            if event.key == pygame.K_r:
                reset_game()
            if event.key == pygame.K_q:
                running = False

    if not paused and not game_over and not you_win:
        keys = pygame.key.get_pressed()
        # Player movement
        if (
            keys[pygame.K_UP]
            and player_pos[0] > 0
            and grid[player_pos[0] - 1][player_pos[1]] == 0
        ):
            player_pos[0] -= 1
        if (
            keys[pygame.K_DOWN]
            and player_pos[0] < ROWS - 1
            and grid[player_pos[0] + 1][player_pos[1]] == 0
        ):
            player_pos[0] += 1
        if (
            keys[pygame.K_LEFT]
            and player_pos[1] > 0
            and grid[player_pos[0]][player_pos[1] - 1] == 0
        ):
            player_pos[1] -= 1
        if (
            keys[pygame.K_RIGHT]
            and player_pos[1] < COLS - 1
            and grid[player_pos[0]][player_pos[1] + 1] == 0
        ):
            player_pos[1] += 1

        # Enemy movement
        enemy_tick += 1
        if enemy_tick % 6 == 0:
            path = bfs(enemy_pos, player_pos)
            if len(path) > 1:
                enemy_pos = list(path[1])

        # Check collisions
        if player_pos == enemy_pos:
            game_over = True
        if player_pos == goal_pos:
            you_win = True

    # ----- Draw -----
    screen.fill(WHITE)
    for r in range(ROWS):
        for c in range(COLS):
            rect = pygame.Rect(c * CELL_SIZE, r * CELL_SIZE, CELL_SIZE, CELL_SIZE)
            if grid[r][c] == 1:
                pygame.draw.rect(screen, GRAY, rect)
            pygame.draw.rect(screen, BLACK, rect, 1)

    # Goal
    pygame.draw.rect(
        screen,
        GREEN,
        (goal_pos[1] * CELL_SIZE, goal_pos[0] * CELL_SIZE, CELL_SIZE, CELL_SIZE),
    )
    # Player
    pygame.draw.rect(
        screen,
        BLUE,
        (player_pos[1] * CELL_SIZE, player_pos[0] * CELL_SIZE, CELL_SIZE, CELL_SIZE),
    )
    # Enemy
    pygame.draw.rect(
        screen,
        RED,
        (enemy_pos[1] * CELL_SIZE, enemy_pos[0] * CELL_SIZE, CELL_SIZE, CELL_SIZE),
    )

    # Menu text
    menu_text = "P: Pause | R: Reset | Q: Quit"
    text_surface = font.render(menu_text, True, BLACK)
    screen.blit(text_surface, (10, HEIGHT - 30))

    # Status messages
    if paused:
        pause_text = font.render("Game Paused", True, RED)
        screen.blit(pause_text, (WIDTH // 2 - 80, HEIGHT // 2))
    if game_over:
        over_text = font.render("GAME OVER! Press R to Reset", True, RED)
        screen.blit(over_text, (WIDTH // 2 - 150, HEIGHT // 2))
    if you_win:
        win_text = font.render("YOU WIN! Press R to Reset", True, GREEN)
        screen.blit(win_text, (WIDTH // 2 - 150, HEIGHT // 2))

    pygame.display.flip()

pygame.quit()
