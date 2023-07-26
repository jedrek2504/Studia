''' Jak coś nie działa to nie narzekać, bo już mi się nie chce poprawiać
    Czemu są różnie teksty i liczby? eeeee, idk xD
    Czasem sprawdzałem dla liczb, czasem dla tekstu, zależnie od przykładu czy zadania na [...]'''


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def is_coprime(x, y):
    return gcd(x, y) == 1


def gcd_ext(a, b, verbose=False):
    if not is_coprime(a, b):
        print("Liczby nie są względnie pierwsze")
        return False

    init_a, init_b = a, b
    multiple_in_list = [-1, -1]
    P_list = [0, 1]
    Q_list = [1, 0]
    N_list = [-2, -1]
    i = 2
    if (a < b):
        a, b = b, a
        multiple_in_list.append(0)
        P_list.append(multiple_in_list[i] * P_list[i - 1] + P_list[i - 2])
        Q_list.append(multiple_in_list[i] * Q_list[i - 1] + Q_list[i - 2])
        N_list.append(i - 2)
        i += 1

    while b != 0:
        N_list.append(i - 2)
        multiple_in_list.append(a // b)
        P_list.append(multiple_in_list[i] * P_list[i - 1] + P_list[i - 2])
        Q_list.append(multiple_in_list[i] * Q_list[i - 1] + Q_list[i - 2])
        a, b = b, a % b
        i += 1
    P_value = (-1) ** (N_list[-2]) * P_list[-2]
    Q_value = (-1) ** (N_list[-2]) * Q_list[-2]
    QmodB = Q_value % init_b
    PmodA = P_value % init_a
    if verbose:
        print('n', end='\t')
        for i in N_list:
            print(i, end='\t')

        print('\n')

        print('q_n', end='\t')
        for i in multiple_in_list:
            print(i, end='\t')

        print('\n')

        print('P_n', end='\t')
        for i in P_list:
            print(i, end='\t')

        print('\n')

        print('Q_n', end='\t')
        for i in Q_list:
            print(i, end='\t')

        print()

        print(f"x = {P_value}, y = {Q_value}")

        print(f"{Q_value}(mod {init_b}) = {QmodB} <- to na interesuje w odwrotnosci")
        print(f"{P_value}(mod {init_a}) = {PmodA}")
        print(f"{init_a}*x - {init_b}*y = 1")
        print(f"{init_a}*{QmodB} - {init_b}*{PmodA} = 1")
    # Dawno takiego spaghetti nie pisałem xD
    return QmodB


def backpack_public_from_secret(secret_list, n: int, m: int):
    if not is_coprime(n, m): return False
    public_key_list = []
    for i in secret_list:
        public_key_list.append((i * n) % m)

    print(f'Klucz jawny -> {public_key_list}')


def backpack_crypt(publicKey, mess: str):  # Powinienem zakladac, ze wiadomosc bedzie w postaci bitowej?
    chunks, chunk_size = len(mess), len(publicKey)
    split_mess = [mess[i:i + chunk_size] for i in range(0, chunks, chunk_size)]
    crypted = []  # masy plecaków?
    for block in split_mess:
        sum = 0
        for i, char in enumerate(block):
            if char == '1': sum += publicKey[i]
        crypted.append(sum)
    crypted = [i for i in crypted if i != 0]
    print(crypted)


def backpack_decrypt(secretKey, encr_mess, n: int, m: int):
    reversed_n = gcd_ext(n, m)
    secretKey = secretKey[::-1]
    bits_list = []
    for i in encr_mess:
        x = (i * reversed_n) % m
        bits = ''
        for j in secretKey:
            if x >= j:
                x = x - j
                bits += '1'
            else:
                bits += '0'
        bits_list.append(bits[::-1])
    print(bits_list)


def RSA_crypt(p: int, q: int, e: int, mess: str):
    n = p * q  # idk czy robic to, że p*q > N
    fi_n = (p - 1) * (q - 1)
    if e > fi_n or not is_coprime(e, fi_n): return False
    # I juz nawet nie sprawdzam tego, ze 'e' musi być tego samego rzędu co 'n'
    private_key = gcd_ext(e, fi_n)

    chunks, chunk_size = len(mess), len(
        str(private_key))  # To w przykladzie bylo 4, ale nie wiem ile naprawde powinno być
    split_mess = [mess[i:i + chunk_size] for i in range(0, chunks, chunk_size)]
    encrypted_list = []
    for m in split_mess:
        m = int(m)
        encrypted_list.append(str((m ** e) % n))
    print(f"Zaszyfrowana wiadomosc -> {''.join(encrypted_list)}")


def RSA_decrypt(mess: int, private_key: int, p: int, q: int, e=None):
    if not e:
        print(f"Deszyfrowana wiadomosc -> {(mess ** private_key) % (p * q)}")
    else:
        print(f"Deszyfrowana wiadomosc -> {(mess ** gcd_ext(e, (p - 1) * (q - 1))) % (p * q)}")


def ElGamal_crypt(p: int, g: int, a: int, r: int, mess: int):
    if g < 1 or g >= (p - 1):  # Rząd wielkości?
        return False
    if a < 1 or a >= (p - 1):
        return False
    if r < 0 or r > (p - 1):
        return False

    h: int = g ** a
    c1: int = (g ** r) % p
    c2: int = (mess * (h ** r)) % p
    print(f"Szyfr -> c1 = {c1}, c2 = {c2}")


def ElGamal_decrypt(c1: int, c2: int, p: int, private_key: int):
    decrypted_mess = (c2 * (gcd_ext(c1 ** private_key, p))) % p
    print(f'Odszyfrowane -> {decrypted_mess}')


def Blum_Micali_crypt(a: int, p: int, seed: int, mess: str):
    if not is_coprime(a, p):
        print("These numbers are not coprime")
        return False
    crypting_bits = []
    seed = (a ** seed) % p
    for i, char in enumerate(mess):
        if seed > (p - 1) / 2:
            crypting_bits.append('1')
        else:
            crypting_bits.append('0')
        seed = (a ** seed) % p
    crypting_bits = ''.join(crypting_bits)
    encrypted = []
    for i, j in zip(mess, crypting_bits):
        if i == j:
            encrypted.append('0')
        else:
            encrypted.append('1')
    print(f"Message ->\t\t  {mess}")
    print(f"Key used to encrypt(XOR)->{crypting_bits}")
    print(f"Encrypted ->\t\t  {''.join(encrypted)}")


def RSA_generator_crypt_idk(e: int, n: int, seed: int, mess: str):
    # if not is_coprime(e, n):
    #     print("These numbers are not coprime")
    #     return False
    crypting_bits = []
    seed = (seed ** e) % n
    for i, char in enumerate(mess):
        lsb = seed & 1
        crypting_bits.append(str(lsb))
        seed = (seed ** e) % n
    crypting_bits = ''.join(crypting_bits)
    encrypted = []
    for i, j in zip(mess, crypting_bits):
        if i == j:
            encrypted.append('0')
        else:
            encrypted.append('1')
    print(f"Message ->\t\t  {mess}")
    print(f"Key used to encrypt(XOR)-> {crypting_bits}")
    print(f"Encrypted/decrypted whatever you want-> {''.join(encrypted)}")


def Schnorr_signature(mess: int, p: int, q: int, h: int, a: int, r: int, fun):
    X = (h ** r) % p
    s1 = fun(int(str(mess) + str(X)))
    s2 = (r + a * s1) % q
    return (s1, s2)


def Schnorr_verify(mess: int, p: int, h: int, a: int, s1: int, s2: int, fun):
    v = gcd_ext(h ** a, p)
    Z = ((h ** s2) * (v ** s1)) % p
    sth = fun(int(str(mess) + str(Z)))
    if s1 == sth:
        print("Zweryfikowane xD")
        print(f"Liczba weryfikująca: {sth}")
    else:
        print("Oj byczq nie zweryfikowany")
        print(f"Liczba NIEweryfikująca: {sth}")


def DSA_signature(mess: int, p: int, q: int, h: int, a: int, r: int, fun):
    r_rev = gcd_ext(r, q)
    s1 = ((h ** r) % p) % q
    s2 = (r_rev * (fun(mess) + (a * s1))) % q
    return s1, s2


def DSA_verify(mess: int, p: int, q: int, a: int, h: int, s1: int, s2: int, fun):
    b = (h ** a) % p
    s_rev = gcd_ext(s2, q)
    u1 = (fun(mess) * s_rev) % q
    u2 = (s1 * s_rev) % q
    t = (((h ** u1) * (b ** u2)) % p) % q
    if t == s1:
        print("Zweryfikowane xD")
        print(f"Liczby weryfikujące: ({s1},{t})")
    else:
        print("Oj byczq nie zweryfikowany")
        print(f"Liczby NIEweryfikujące: ({s1},{t})")


def Chooser():
    choice = input("No wybierz cos: ")
    if (choice == '1'):
        a = int(input("Pierwsza liczba -> "))
        b = int(input("Druga liczba -> "))
        gcd_ext(a, b, True)
    elif (choice == '2'):
        a = int(input("Pierwsza liczba: "))
        b = int(input("Druga liczba: "))
        if is_coprime(a, b):
            print("Są względnie pierwsze")
        else:
            print("nie są względnie pierwsze lol")
    elif (choice == '3'):
        secret_key = input("Podaj ciąg liczb sekretnego klucza rozdzielając spacją: ")
        secret_key = secret_key.split(' ')
        secret_key = [int(i) for i in secret_key]
        n = int(input("Podaj liczbę 'n': "))
        m = int(input("Podaj liczbe 'm': "))
        backpack_public_from_secret(secret_key, n, m)
    elif (choice == '4'):
        secret_key = input("Podaj ciąg liczb klucza rozdzielając spacją: ")
        secret_key = secret_key.split(' ')
        secret_key = [int(i) for i in secret_key]
        mess = input("Podaj wiadomosc do zaszyfrowania: ")
        backpack_crypt(secret_key, mess)
    elif (choice == '5'):
        secret_key = input("Podaj ciąg liczb klucza rozdzielając spacją: ")
        secret_key = secret_key.split(' ')
        secret_key = [int(i) for i in secret_key]
        encr_mess = input("Podaj ciąg liczb szyfrogramu rozdzielając spacją: ")
        encr_mess = encr_mess.split(' ')
        encr_mess = [int(i) for i in encr_mess]
        n = int(input("Podaj liczbę 'n': "))
        m = int(input("Podaj liczbe 'm': "))
        backpack_decrypt(secret_key, encr_mess, n, m)
    elif (choice == '6'):
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbe 'q': "))
        e = int(input("Podaj liczbę 'e': "))
        mess = (input("Podaj wiadomość do zaszyfrowania: "))
        RSA_crypt(p, q, e, mess)
    elif (choice == '7'):
        print("Jeżeli nie masz klucza prywatnego, to podaj tam 0, ale wpisz 'e'")
        print("I odwrotnie tak samo, wpisz klucz, to wtedy do 'e' możesz 0 ")
        private_key = int(input("Podaj prywatny klucz (liczba): "))
        mess = int(input("Podaj wiadomość do zaszyfrowania (liczba): "))
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbe 'q': "))
        e = int(input("Podaj liczbę 'e': "))
        if e == 0:
            RSA_decrypt(mess, private_key, p, q)
        else:
            RSA_decrypt(mess, private_key, p, q, e)
    elif (choice == '8'):
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbe 'q': "))
        a = int(input("Podaj liczbę 'a': "))
        r = int(input("Podaj liczbę 'r': "))
        mess = int(input("Podaj wiadomość (liczba): "))
        ElGamal_crypt(p, q, a, r, mess)
    elif (choice == '9'):
        c1 = int(input("Podaj liczbę 'c1': "))
        c2 = int(input("Podaj liczbe 'c2': "))
        p = int(input("Podaj liczbę 'p': "))
        private_key = int(input("Podaj klucz prywatny (liczba): "))
        ElGamal_decrypt(c1, c2, p, private_key)
    elif (choice == '10'):
        a = int(input("Podaj liczbę 'a': "))
        p = int(input("Podaj liczbe 'p': "))
        seed = int(input("Podaj seed (liczba): "))
        mess = (input("Podaj wiadomość (tekst): "))
        Blum_Micali_crypt(a, p, seed, mess)
    elif (choice == '11'):
        e = int(input("Podaj liczbę 'e': "))
        n = int(input("Podaj liczbe 'n': "))
        seed = int(input("Podaj seed (liczba): "))
        mess = (input("Podaj wiadomość (tekst): "))
        RSA_generator_crypt_idk(e, n, seed, mess)
    elif (choice == '12'):
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbe 'q': "))
        h = int(input("Podaj liczbę 'h': "))
        a = int(input("Podaj liczbę 'a': "))
        r = int(input("Podaj liczbę 'r': "))
        mess = int(input("Podaj wiadomość (liczba): "))
        fun = lambda x: x
        # fun = lambda x: 1
        print("Funkcja haszująca jest ustawiona jako f(x) = x !!!!")
        print("Jak potrzeba coś innego to wystarczy zmienić w kodzie lambda, albo odkomentować")
        s1, s2 = Schnorr_signature(mess, p, q, h, a, r, fun)
        print(f"s1 -> {s1}")
        print(f"s2 -> {s2}")
    elif (choice == '13'):
        p = int(input("Podaj liczbę 'p': "))
        h = int(input("Podaj liczbę 'h': "))
        a = int(input("Podaj liczbę 'a': "))
        s1 = int(input("Podaj liczbę 's1': "))
        s2 = int(input("Podaj liczbę 's2': "))
        mess = int(input("Podaj wiadomość (liczba): "))
        fun = lambda x: x
        # fun = lambda x: 1
        print("Funkcja haszująca jest ustawiona jako f(x) = x !!!!")
        print("Jak potrzeba coś innego to wystarczy zmienić w kodzie lambda, albo odkomentować")
        Schnorr_verify(mess, p, h, a, s1, s2, fun)
    elif (choice == '14'):
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbe 'q': "))
        h = int(input("Podaj liczbę 'h': "))
        a = int(input("Podaj liczbę 'a': "))
        r = int(input("Podaj liczbę 'r': "))
        mess = int(input("Podaj wiadomość (liczba): "))
        # fun = lambda x: x
        fun = lambda x: 1
        print("Funkcja haszująca jest ustawiona jako f(x) = 1 !!!!")
        print("Jak potrzeba coś innego to wystarczy zmienić w kodzie lambda, albo odkomentować")
        s1, s2 = DSA_signature(mess, p, q, h, a, r, fun)
        print(f"s1 -> {s1}")
        print(f"s2 -> {s2}")
    elif (choice == '15'):
        p = int(input("Podaj liczbę 'p': "))
        q = int(input("Podaj liczbę 'q': "))
        h = int(input("Podaj liczbę 'h': "))
        a = int(input("Podaj liczbę 'a': "))
        s1 = int(input("Podaj liczbę 's1': "))
        s2 = int(input("Podaj liczbę 's2': "))
        mess = int(input("Podaj wiadomość (liczba): "))
        fun = lambda x: x
        # fun = lambda x: 1
        print("Funkcja haszująca jest ustawiona jako f(x) = x !!!!")
        print("Jak będzie coś innego to wystarczy zmienić w kodzie lambda, albo odkomentować")
        DSA_verify(mess, p, q, a, h, s1, s2, fun)
    else:
        print("Zły klawisz xD")
        print("Zapraszamy w kolejnym zgłoszeniu")
        quit()


def main():
    print("Wybierz '1' -> liczenie liczby odwrotnej modulo (TABELKA)")
    print("Wybierz '2' -> czy liczby są względnie pierwsze")
    print("Wybierz '3' -> klucz publiczny z prywatnego, w algorytmie plecakowym")
    print("Wybierz '4' -> szyfrowanie ciągu bitowego w formie tekstu, algorytmem plecakowym")
    print("Wybierz '5' -> DEszyfrowanie ciągu liczb algorytmem plecakowym")
    print("Wybierz '6' -> szyfrowanie tekstu w RSA")
    print("Wybierz '7' -> DEszyfrowanie liczby w RSA")
    print("Wybierz '8' -> szyfrowanie liczby ElGamalem")
    print("Wybierz '9' -> DEszyfrowanie liczby ElGamalem")
    print("Wybierz '10'-> szyfrowanie/deszyfrowanie tekstu BlumMicali (strumieniowy)")
    print("Wybierz '11'-> szyfrowanie/deszyfrowanie tekstu RSA (strumieniowy)")
    print("Wybierz '12' -> Sznorr sygnatura generowanie")
    print("Wybierz '13' -> Sznorr weryfikacja")
    print("Wybierz '14' -> DSA sygnatura generowanie")
    print("Wybierz '15' -> DSA weryfikacja")
    print()
    Chooser()

    "Tutaj niżej są przykłady na których testowałem działanie, można się pobawić idk?"

    # gcd_ext(8, 35, True)
    # gcd_ext(31, 105, True)
    # if not backpack_public_from_secret([2, 3, 6, 13, 27, 52], 31, 105): print("Liczby n i m nie są względnie pierwsze")
    # backpack_crypt([62, 93, 81, 88, 102, 37], "011000110101101110")
    # backpack_decrypt([2, 3, 6, 13, 27, 52], [174, 280, 333], 31, 105)
    # RSA_crypt(53, 67, 1021, '123')
    # RSA_decrypt(2393, 1237, 53, 67)
    # ElGamal_crypt(23, 5, 6, 10, 7)
    # ElGamal_decrypt(9, 21,() 23, 6)
    # gcd_ext(3, 14, True) # Z dysku
    # gcd_ext(5, 12, True) # Z dysku
    # ElGamal_decrypt(2, 1, 7, 4)
    # gcd_ext(34319, 5, True)
    # Blum_Micali_crypt(300, 97, 37, '0011001111001100')
    # RSA_generator_crypt_idk(2393, 1237, 513, '0011001111001100')

    # f_x = lambda x: x
    # f1 = lambda x: 1
    # s1, s2 = Schnorr_signature(1, 7, 3, 2, 4, 2, f_x) 
    # Schnorr_verify(1, 7, 2, 4, s1, s2, f_x) # teoretycznie git

    # s1, s2 = Schnorr_signature(3, 7, 3, 2, 4, 2, f_x) 
    # Schnorr_verify(3, 7, 2, 4, s1, s2, f_x) 

    # s1, s2 = DSA_signature(1221, 7, 3, 2, 2, 1, f1)
    # DSA_verify(1221, 7, 3, 2, 2, s1, s2, f1)

    # RSA_decrypt(2, 0, 3, 5, 3) # ten drugi sposob dla rsa bez podanego klucza

    # key = RSA_generator_crypt_idk(5, 21, 3, '101') 

    # gcd_ext(3, 14, True)

    # ElGamal_decrypt(2, 1, 7, 4)


if __name__ == '__main__':
    main()
