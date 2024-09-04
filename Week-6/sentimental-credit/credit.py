from cs50 import get_string


def main():

    credit_number = input("Number: ")

    if luhn(credit_number):
        company(credit_number)
    else:
        print("INVALID")


def luhn(n):
    if 13 <= len(n) <= 16:
        every_other_digit = 0
        odds_digit_sum = 0
        evens_digit_sum = 0
        for char in reversed(n):
            if every_other_digit % 2 != 0:
                # print(int(char) * 2, " " ,end = "")
                one_digit = int(char) * 2
                if one_digit > 9:
                    odds_digit_sum += one_digit // 10
                    odds_digit_sum += one_digit % 10
                else:
                    odds_digit_sum += one_digit
            else:
                evens_digit_sum += int(char)
            every_other_digit += 1
        if (evens_digit_sum + odds_digit_sum) % 10 == 0:
            return True
        else:
            return False
    else:
        return False


def company(n):

    if n[0:2] == "51" or n[0:2] == "52" or n[0:2] == "53" or n[0:2] == "54" or n[0:2] == "55":
        print("MASTERCARD")
    elif n[0:2] == "34" or n[0:2] == "37":
        print("AMEX")
    elif n[0] == "4":
        print("VISA")
    else:
        print("INVALID")


main()
