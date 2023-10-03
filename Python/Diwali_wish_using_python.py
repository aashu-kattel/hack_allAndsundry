from tkinter.font import ITALIC
from tkinter.ttk import Style
import turtle
import colorsys
import random

screen=turtle.Screen()

screen.setup(1200,600)

screen.bgcolor('black')

t=turtle.Turtle()
turtle.title("Copy Assignment Turtle")

t.speed(10)

t.hideturtle()
hue=0.0

size=random.randint(10,200)


def write(message,pos):
        x,y=pos
    
        t.pencolor("orange")
        t.penup()
        t.goto(x,y)
        style=('Arial',100)
        t.write(message,font=style)

write('Happy Diwali',(-380,-50))

def draw_firecrackers(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()


t.color("red")


angle=0
for i in range(20):
    #move in forward direction
    t.fd(50)

    #calling the function and initializing the values
    draw_firecrackers(300,180)

    #changing the angle of pointer
    angle+=18

    t.left(angle)
draw_firecrackers(450,180)

#color of the firecracker
t.color("blue")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(450,180)
draw_firecrackers(375,300)

#color of the firecracker
t.color("green")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(375,300)
draw_firecrackers(375,-300)

#color of the firecracker
t.color("orange")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(375,-300)
draw_firecrackers(150,-150)

#color of the firecracker
t.color("violet")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(150,-150)
draw_firecrackers(450,-150)

#color of the firecracker
t.color("brown")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(450,-150)
draw_firecrackers(-200,-300)

#color of the firecracker
t.color("green")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(-200,-300)
draw_firecrackers(125,0)

#color of the firecracker
t.color("pink")
angle=0
draw_firecrackers(-100,-200)
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(-100,-200)

#color of the firecracker    
t.color("skyblue")
angle=0
draw_firecrackers(-500,-240)
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(-500,-240)

#color of the firecracker    
t.color("orange")
angle=0
draw_firecrackers(-350,-170)
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(-350,-170)

#color of the firecracker
t.color("pink")
angle=0
for i in range(20):
    t.fd(50)
    draw_firecrackers(-550,300)
    angle+=18
    t.left(angle)
draw_firecrackers(-450,180)

#color of the firecracker
t.color("green")
angle=0
for i in range(20):
    t.fd(50)
    angle+=18
    t.left(angle)
    draw_firecrackers(-450,180)
draw_firecrackers(-375,300)
t.color("yellow")
angle=0
for i in range(20):
    t.fd(50)
    t.left(angle)
    angle+=18
    draw_firecrackers(-375,300)
draw_firecrackers(-375,-300)

# To hold the screen to display
screen.mainloop
