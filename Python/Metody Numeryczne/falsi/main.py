import functions
import graphs


def menu():
    flag = 1
    func = 0
    c_b = 0
    c_f = 0
    error_b = 0
    error_f = 0
    counter_b = 0
    counter_f = 0

    # loop until the user decides to exit
    while flag:
        # available functions
        print("Functions:\n1. x^3 + 5x^2 - 2x - 10\n"
              "2. 3 * cos(0.5 * x) + 2\n"
              "3. 2^x - 5\n"
              "4. e^x - 5 * cos(x-1)")

        # get the function number
        function_no = int(input("Choose function number: "))

        # set the function to be used based on function number
        if 1 <= function_no <= 4:
            if function_no == 1:
                graphs.pylab.ylim(-100, 100)
                graphs.drawGraph(-8, 8, function_no, 'no')
                func = 1
            if function_no == 2:
                graphs.pylab.ylim(-2, 7)
                graphs.drawGraph(-25, 25, function_no, 'no')
                func = 2
            if function_no == 3:
                graphs.pylab.ylim(-6, 5)
                graphs.drawGraph(-10, 10, function_no, 'no')
                func = 3
            if function_no == 4:
                graphs.pylab.ylim(-10, 20)
                graphs.drawGraph(-30, 4, function_no, 'no')
                func = 4
        else:
            print("No such function! Aborting...")
            return

        # get the interval
        a = float(input("Beginning of an interval: "))
        b = float(input("End of an interval: "))

        # get the stopping condition
        print("\nChoose stop condition:\neps - epsilon\nit - iterations")
        stop = str(input("Answer: "))

        # continue program based on chosen stopping condition
        if stop == "eps":
            eps = float(input("You chose epsilon. Enter value of epsilon[0;1]"))
            c_b, error_b, counter_b = functions.bisection(func, a, b, eps, None)
            c_f, error_f, counter_f = functions.false_position(func, a, b, eps, None)
            graphs.pylab.xlabel('Bisection')
            graphs.drawGraph(a, b, function_no, c_b)
            graphs.pylab.xlabel('False position')
            graphs.drawGraph(a, b, function_no, c_f)

            # display the results
            print(f"\nResults using method {stop}:\n"
                  "\nBisection:\n"
                  f"Approximate result x0 = {c_b}\n"
                  f"error = {error_b}\n"
                  f"counter = {counter_b}\n"
                  f"score = {error_b * counter_b}\n\n"
                  "False_position:\n"
                  f"Approximate result x0 = {c_f}\n"
                  f"error = {error_f}\n"
                  f"counter = {counter_f}\n"
                  f"score = {error_f * counter_f}\n")

            # announcing who the winner is
            if (error_b * counter_b) < (error_f * counter_f):
                print(f"The winner is: Bisection with error = {error_b}\n"
                      f"and no of iterations = {counter_b}\n")
            elif (error_f * counter_f) < (error_b * counter_b):
                print(f"The winner is: Falsi with error = {error_f}\n"
                      f"and no of iterations = {counter_f}\n")
            else:
                print("No winner today - the results are equal")

        elif stop == "it":
            it = int(input("You chose iterations. Enter no of iterations(50+)"))
            c_b, error_b = functions.bisection(func, a, b, None, it)
            c_f, error_f = functions.false_position(func, a, b, None, it)
            graphs.pylab.xlabel('Bisection')
            graphs.drawGraph(a, b, function_no, c_b)
            graphs.pylab.xlabel('False position')
            graphs.drawGraph(a, b, function_no, c_f)

            # display the results
            print(f"\nResults using method {stop}:\n"
                  "\nBisection:\n"
                  f"Approximate result x0 = {c_b}\n"
                  f"error = {error_b}\n\n"
                  "False_position:\n"
                  f"Approximate result x0 = {c_f}\n"
                  f"error = {error_f}\n")

            # announcing who the winner is
            if error_b < error_f:
                print(f"The winner is: Bisection with error smaller by = {error_f - error_b}")
            elif error_f < error_b:
                print(f"The winner is: Falsi with error smaller by = {error_b - error_f}")
            else:
                print("No winner today - the results are equal")
        else:
            print("No such stopping condition! Aborting...")
            return

        # ask the user if they want to quit
        print('Do you want to exit?')
        print('0 - YES\n1 - NO')
        flag = int(input("Answer: "))
        if flag == 0:
            return


# call of the menu function
menu()
