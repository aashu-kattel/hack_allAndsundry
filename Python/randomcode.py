import random

def generate_numbers(count, minimum, maximum):
    """Generate a list of random numbers within a given range."""
    return [random.randint(minimum, maximum) for _ in range(count)]

def find_largest(numbers):
    """Find the largest number in a list of numbers."""
    if not numbers:
        return None
    largest = numbers[0]
    for number in numbers:
        if number > largest:
            largest = number
    return largest

def main():
    print("Welcome to the 'Biggest Number' game!")
    count = int(input("How many numbers do you want to compare? "))
    minimum = int(input("Enter the minimum number in the range: "))
    maximum = int(input("Enter the maximum number in the range:"))

    numbers = generate_numbers(count, minimum, maximum)
    largest_number = find_largest(numbers)

    print(f"Here are the numbers to compare: {numbers}")
    input("Press Enter to find the biggest number...")

    print(f"The biggest number is: {largest_number}")

if __name__ == "__main__":
    main()
