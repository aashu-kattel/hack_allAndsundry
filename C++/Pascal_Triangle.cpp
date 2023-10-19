// This program produce the pascal's triangle for the user inputed rows

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generatePascalsTriangle(int numRows)
{
	std::vector<std::vector<int>> result;
	if (numRows <= 0)
	{
		return result;
	}

	// The first row is always [1].
	result.push_back(std::vector<int>{1});

	for (int i = 1; i < numRows; i++)
	{
		std::vector<int> newRow;
		const std::vector<int> &prevRow = result.back();

		// The first element of each row is always 1.
		newRow.push_back(1);

		for (int j = 1; j < i; j++)
		{
			// Calculate the middle elements based on the sum of two elements from the previous row.
			newRow.push_back(prevRow[j - 1] + prevRow[j]);
		}

		// The last element of each row is always 1.
		newRow.push_back(1);
		result.push_back(newRow);
	}

	return result;
}

// declaring the main function here

int main()
{
	int numRows;
	std::cout << "Enter the number of rows for the Pascal's triangle:- ";
	std::cin >> numRows;

	if (numRows <= 0)
	{
		std::cout << "Number of rows should be greater than zero." << std::endl;
		return 1;
	}

	std::vector<std::vector<int>> pascalsTriangle = generatePascalsTriangle(numRows);

	for (const auto &row : pascalsTriangle)
	{
		for (int num : row)
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
