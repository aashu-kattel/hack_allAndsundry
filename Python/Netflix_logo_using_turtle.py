import turtle
from time import sleep

# Create a Turtle graphics window and set the speed
t = turtle.Turtle()
t.speed(4)

# Set the background color and title of the window
turtle.bgcolor("white")
turtle.title('Netflix Logo')

# Move the turtle to an initial position for drawing
t.up()
t.goto(-80, 50)
t.down()

# Set the fill color for the Netflix logo and start filling
t.fillcolor("black")
t.begin_fill()

# Draw the outer shape of the Netflix logo
t.forward(200)
t.setheading(270)
s = 360
for i in range(9):
    s = s - 10
    t.setheading(s)
    t.forward(10)

t.forward(180)
s = 270
for i in range(9):
    s = s - 10
    t.setheading(s)
    t.forward(10)

t.forward(200)
s = 180
for i in range(9):
    s = s - 10
    t.setheading(s)
    t.forward(10)

t.forward(180)
s = 90
for i in range(9):
    s = s - 10
    t.setheading(s)
    t.forward(10)

# Complete the fill for the outer shape
t.forward(30)
t.end_fill()

# Move to draw the red "N" in the Netflix logo
t.up()
t.color("black")
t.setheading(270)
t.forward(240)
t.setheading(0)
t.down()
t.color("red")
t.fillcolor("#E50914")
t.begin_fill()

# Draw the red "N"
t.forward(30)
t.setheading(90)
t.forward(180)
t.setheading(180)
t.forward(30)
t.setheading(270)
t.forward(180)
t.end_fill()

# Move to draw the second "N" in the Netflix logo
t.setheading(0)
t.up()
t.forward(75)
t.down()
t.color("red")
t.fillcolor("#E50914")
t.begin_fill()

# Draw the second "N"
t.forward(30)
t.setheading(90)
t.forward(180)
t.setheading(180)
t.forward(30)
t.setheading(270)
t.forward(180)
t.end_fill()

# Draw the bottom red shape of the Netflix logo
t.color("red")
t.fillcolor("red")
t.begin_fill()
t.setheading(113)
t.forward(195)
t.setheading(0)
t.forward(31)
t.setheading(293)
t.forward(196)
t.end_fill()

# Hide the turtle and pause the program for 10 seconds
t.hideturtle()
sleep(10)
