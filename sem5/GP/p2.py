import pygame
import sys
import math

pygame.init()

width,height=800,600
screen=pygame.display.set_mode((width,height))
pygame.display.set_caption("2D Transformations")

white=(255,255,255)
red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)

clock=pygame.time.Clock()

shape_width,shape_height=100,60
orignal_shape=pygame.Surface((shape_width,shape_height))
orignal_shape.fill(red)

angle=0
scale_factor=1.0
position=[350,270]

running=True
while running:
    screen.fill(white)

    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            running=False

    scaled_shape=pygame.transform.scale(orignal_shape,(int(shape_width*scale_factor),int(shape_height*scale_factor)))
    rotated_shape=pygame.transform.rotate(scaled_shape,angle)
    rect=rotated_shape.get_rect(center=(position[0],position[1]))
    screen.blit(rotated_shape,rect)
    angle+=1
    scale_factor+=0.005

    if scale_factor>2:
        scale_factor=1.0

    pygame.draw.rect(screen,blue,(50,50,shape_width,shape_height),2)
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
