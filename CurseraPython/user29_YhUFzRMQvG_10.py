# template for "Guess the number" mini-project
# input will come from buttons and an input field

import simplegui
import random
import math


# initialize global variables used in your code
num_range=100
num_guess=0
secret_number=0


# helper function to start and restart the game
def new_game():    
    global secret_number
    global num_guess
    secret_number=random.randrange(0,num_range)
    num_guess=int(math.ceil(math.log(num_range,2)))
    print
    print "new game"
    print "range is from 0 to " + str(num_range)
    print "number of remaining guess "+str(num_guess)


# define event handlers for control panel
def range100():
    global num_range
    global num_guess
    num_range=100
    new_game()

def range1000():
    global num_range
    global num_guess
    num_range=1000
    new_game()
    
def input_guess(guess):
    # main game logic goes here	
    global num_guess
    guess_number=int(guess)
    num_guess=num_guess-1
    print
    print "guess was "+guess
    print "number of remaining guesses is "+str(num_guess)
    if guess_number==secret_number:
        print "correct"
        new_game()
        return
    
    if num_guess==0:
        print "you ran out guess, the secret number is "+str(secret_number)
        new_game()
        return
    
    if guess_number>secret_number:
        print "lower"
    else:    
        print "higer"
    
        
 

    
# create frame
f=simplegui.create_frame("Guess the number",200,200)



# register event handlers for control elements
f.add_button("Range is [0,100)",range100,200)
f.add_button("Range is [0,1000)",range1000,200)
f.add_input("Enter a guess", input_guess, 200)

# call new_game and start frame
new_game()


# always remember to check your completed program against the grading rubric
