import numpy as np
from numpy.linalg import inv


# Tworzenie macierzy diagonalnej D, która jest macierzą,
# w której elementy poza przekątną są równe zero, a elementy na przekątnej
# są równomiernie rozmieszczone elementy macierzy A.
def matrixDiagonalD(A):
    return np.diag(np.diag(A))


# Odwracanie macierzy diagonalnej D.
def inverse(A):
    return inv(A)


# Tworzenie macierzy LU, która jest równa macierzy A pomniejszonej o macierz diagonalną D.
def matrixLU(A, D):
    LU = A - D
    return LU


# Tworzenie macierzy T, która jest wynikiem mnożenia macierzy odwrotności D i LU ze znakiem przeciwnym.
def matrixT(D, LU):
    T = -inverse(D) @ LU
    return T


# Tworzenie macierzy C, która jest wynikiem mnożenia macierzy odwrotności D i wektora b.

def matrixC(D, b):
    C = inverse(D) @ b
    return C


def jacobi(A, b, iterations, eps):
    licznik = 0
    # Step 1: Create diagonal matrix D with elements from A diagonal
    D = matrixDiagonalD(A)

    # Step 2: Compute LU matrix as A - D
    LU = matrixLU(A, D)

    # Step 3: Compute T matrix as -D_inv @ LU
    T = matrixT(D, LU)

    # Step 4: Compute C matrix as D_inv @ b
    C = matrixC(D, b)

    # Step 5: Set initial solution vector to zero
    x_new = np.zeros_like(b)
    x_old = x_new

    # Step 6: Iterate until convergence or maximum iterations reached
    while not (((np.allclose(x_new, x_old, atol=eps)) and licznik > 1) or licznik >= iterations):
        x_old = x_new
        x_new = (T @ x_old) + C
        licznik += 1
    print(f'Ilosc iteracji {licznik}')

    # Step 7: Return the final solution vector
    return x_new


# zwraca wartość True, jeśli macierz spełnia warunek zbieżności (czyli przekątna jest dominująca),
# a False w przeciwnym przypadku. Funkcja sprawdza, czy wartość bezwzględna
# elementu na przekątnej jest większa niż suma wartości bezwględnych pozostałych elementów w wierszu.
def is_diagonally_dominant(matrix):
    # Sprawdzenie, czy macierz jest kwadratowa
    if matrix.shape[0] != matrix.shape[1]:
        return False

    # Sprawdzenie, czy macierz jest diagonalnie dominująca
    for i in range(matrix.shape[0]):
        if abs(matrix[i, i]) <= np.sum(np.abs(matrix[i, :])) - abs(matrix[i, i]):
            return False

    return True


def permute_rows(matrix, vector):
    """
    Zmienia kolejność wierszy macierzy i wektora na każdy możliwy sposób.

    Args:
        matrix (np.ndarray): macierz do przestawienia wierszy
        vector (np.ndarray): wektor do przestawienia

    Returns:
        bool: True, jeśli którykolwiek z przestawionych wariantów macierzy jest diagonalnie dominujący, w przeciwnym razie False
    """
    num_rows = matrix.shape[0]
    indices = np.arange(num_rows)
    permutations = np.array(np.meshgrid(*[indices] * num_rows)).T.reshape(-1, num_rows)

    for perm in permutations:
        permuted_matrix = matrix[perm]
        if is_diagonally_dominant(permuted_matrix):
            matrix[:] = permuted_matrix
            vector[:] = vector[perm]
            return True

    return False
