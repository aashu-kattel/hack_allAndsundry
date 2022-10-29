using System;

namespace SearchAlgorithm
{
    class BinarySearch
    {
        //Implementation of Binary Search algorithm
        /// <summary>
        ///     Find the index of an element in an array using the Binary Search algorithm.
        /// </summary>
        /// <param name="array">Array to search for the element.</param>
        /// <param name="element">Element to search for.</param>
        /// <returns>The index [int] of the element in the array. Null if the element was not found.</returns>
        static int? BinarySearchAlgorithm(int[] array, int element)
        {
            int low = 0, high = array.Length - 1, mid;

            while (low <= high)
            {
                mid = (low + high) / 2;
                if (element == array[mid])
                    return mid;
                if (element > array[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return null;
        }


        static void Main(string[] args)
        {
            //takes the length of the array
            Console.Write("Enter the length of the array: ");
            int[] array = new int[Convert.ToInt32(Console.ReadLine())];

            //takes the array elements
            Console.WriteLine("\nEnter the array elements: ");
            for(int i = 0; i < array.Length; i++)
            {
                Console.Write($"[{i}] = ");
                array[i] = Convert.ToInt32(Console.ReadLine());
            }

            //prints the array
            Console.WriteLine("\nThe array is: [{0}]", string.Join(", ", array));

            //sort array
            Array.Sort(array);
            Console.WriteLine("\nThe sorted array is: [{0}]", string.Join(", ", array));

            //takes the element to search
            Console.Write("\nEnter the value to search: ");
            int value = Convert.ToInt32(Console.ReadLine());

            //prints the index of the element in the array
            int? index = BinarySearchAlgorithm(array, value);
            Console.WriteLine("Element " + value + (index != null ? " found at index: " + Convert.ToInt32(index) : " not found"));
        }
    }
}
