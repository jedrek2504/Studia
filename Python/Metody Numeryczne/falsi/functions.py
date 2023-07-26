import math


# Calculates polymonial function using Horner's method
def horner(x, tab, length):
    res = tab[0]
    for i in range(1, length):
        res = res * x + tab[i]
    return res


# Calculates the false position
def calculateFP(fa, fb, a, b):
    return (fa * b - fb * a) / (fa - fb)


# Calculates value of a given function func in a given point x
def calcValAtPt(func, x):
    if func == 1:
        tab = [1, 5, -2, -10]  # x^3 + 5x^2 -2x - 10
        return horner(x, tab, len(tab))
    if func == 2:
        return 3 * math.cos(0.5 * x) + 2
    if func == 3:
        return 2 ** x - 5
    if func == 4:
        return math.e ** x - 5 * math.cos(x - 1)


def false_position(func, a, b, eps, it):
    c = 0

    # Calculate the values of the function at the endpoints
    fa = calcValAtPt(func, a)
    fb = calcValAtPt(func, b)

    # Check if the interval contains a root
    if fa * fb > 0:
        print("Requirements have not been met! Given interval is invalid.")
        return

    else:
        if it is not None:
            # Perform the specified number of iterations
            for i in range(it):
                # Calculate the false position
                c = calculateFP(fa, fb, a, b)
                fc = calcValAtPt(func, c)

                # Check if the false position is the root
                if fc == 0:
                    return c, abs(a - b)

                # Update the interval
                elif fc * fa < 0:
                    b = c
                elif fc * fb < 0:
                    a = c
                else:
                    print("Something went wrong!")
                    return

            # Return the final approximation
            return c, abs(a - b)

        elif eps is not None:
            # Declaration of counter used to specify how many times while loop has been iterated
            counter = 0

            # Iterate until the width of the interval is less than eps
            while abs(b - a) >= eps:
                # Incrementation of the counter
                counter = counter + 1

                # Calculate the false position
                c = calculateFP(fa, fb, a, b)
                fc = calcValAtPt(func, c)

                # Check if the false position is the root
                if fc == 0:
                    return c, abs(a - b), counter

                # Update the interval
                elif fa * fc < 0:
                    b = c
                    fb = fc
                elif fb * fc < 0:
                    a = c
                    fa = fc
                else:
                    print("Something went wrong!")

            # Return the final approximation width of the interval and how many times the loop has been iterated
            return c, abs(b - a), counter
        else:
            print("Must specify eps or it!")
            return


def bisection(func, a, b, eps, it):
    c = 0
    # Calculate the values of the function at the endpoints
    fa = calcValAtPt(func, a)
    fb = calcValAtPt(func, b)

    # Check if the interval contains a root
    if fa * fb > 0:
        print("Requirements have not been met! Given interval is invalid.")
        return

    else:
        if it is not None:
            # Perform the specified number of iterations
            for i in range(it):
                # Calculate the midpoint of the interval
                c = (a + b) / 2
                fc = calcValAtPt(func, c)
                # Check if the midpoint is the root
                if fc == 0:
                    return c

                # Update the interval
                elif fc * fa < 0:
                    b = c
                elif fc * fb < 0:
                    a = c
                else:
                    print("Something went wrong!")
                    return

            # Return the final approximation
            return c, abs(a - b)

        elif eps is not None:
            # Declaration of counter used to specify how many times while loop has been iterated
            counter = 0

            # Iterate until the width of the interval is less than eps
            while abs(b - a) >= eps:
                # Incrementation of the counter
                counter = counter + 1

                # Calculate the midpoint of the interval
                c = (a + b) / 2
                fc = calcValAtPt(func, c)

                # Check if the midpoint is the root
                if fc == 0:
                    return c, abs(a - b), counter

                # Update the interval
                elif fa * fc < 0:
                    b = c
                    fb = fc
                elif fb * fc < 0:
                    a = c
                    fa = fc
                else:
                    print("Something went wrong!")

            # Return the final approximation width of the interval and how many times the loop has been iterated
            return c, abs(b - a), counter
        else:
            print("Must specify eps or it!")
            return
