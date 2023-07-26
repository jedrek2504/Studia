import numpy as np
import matplotlib.pyplot as plt
from numpy.polynomial import Legendre


def choose_function(choice):
    if choice == 1:
        return lambda x: np.abs(x)
    elif choice == 2:
        return lambda x: horner([7, 5, 2, 3], x)  # Horner's method
    elif choice == 3:
        return lambda x: 2 * x + 1
    elif choice == 4:
        return lambda x: np.sin(2 + x)
    elif choice == 5:
        return lambda x: np.cos(x) * x + 5


def horner(coeff, x):
    result = coeff[0]
    for i in range(1, len(coeff)):
        result = result * x + coeff[i]
    return result


def simpson_integral(func, a, b, n):
    h = (b - a) / n
    s = func(a) + func(b)

    for i in range(1, n, 2):
        s += 4 * func(a + i * h)
    for i in range(2, n, 2):
        s += 2 * func(a + i * h)

    return s * h / 3


def approximation_error(func, poly, a, b, n):
    error_func = lambda x: (func(x) - poly(x)) ** 2
    return np.sqrt(simpson_integral(error_func, a, b, n))


def main():
    print("*** menu ***")
    print("1. |x|")
    print("2. 3x^3 + 2x^2 + 5x + 7")
    print("3. 2x + 1")
    print("4. sin(2 + x)")
    print("5. cos(x)*x + 5")

    choice = int(input("Choose function: "))
    func = choose_function(choice)

    a = float(input("Enter the start of the interval: "))
    b = float(input("Enter the end of the interval: "))

    degree = int(input("Enter the degree of the approximating polynomial: "))

    n_nodes = int(input("Enter the number of nodes for the integral method: "))

    x = np.linspace(a, b, 1000)
    y = func(x)
    p = Legendre.fit(x, y, degree)

    plt.figure(figsize=(10, 5))
    plt.plot(x, y, color='red', linestyle='dashed', label="Original Function")
    plt.plot(x, p(x), label="Approximation")
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title(f'Approximation of function using Legendre polynomial of degree {degree}')
    plt.legend()
    plt.grid(True)
    plt.show()

    error = approximation_error(func, p, a, b, n_nodes)
    print("Approximation error:", error)


main()
