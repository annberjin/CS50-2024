def main():
    text = input("Enter: ")

    words = count(text)[0]
    L = count(text)[1] / words * 100
    S = count(text)[2] / words * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print("Grade", index)


def count(text):
    words = 1
    letters = 0
    sentences = 0

    for i in text:
        if i == " ":
            words += 1

        elif i.isalpha():
            letters += 1

        elif i in [".", "!", "?"]:
            sentences += 1

    return words, letters, sentences


if __name__ == "__main__":
    main()
