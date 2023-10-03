# Python3 implementation of the approach
import sys
import math

# Structure of a node of linked list
class Node:
	def __init__(self, data):
		self.next = None
		self.data = data

# Push the new node to front of the linked list
def push(head, data):

	# Return new node as head if head is empty
	if not head:
		return Node(data)
	temp = Node(data)
	temp.next = head
	head = temp
	return head

# Function to find the balanced node
def findBalancedNode(head):
	tsum = 0
	curr_node = head
	
	# Traverse through all node
	# to find the total sum
	while curr_node:
		tsum+= curr_node.data
		curr_node = curr_node.next
	
	# Set current_sum and remaining sum to zero
	current_sum, remaining_sum = 0, 0
	curr_node = head

	# Traversing the list to check balanced node
	while(curr_node):
		remaining_sum = tsum-(current_sum + curr_node.data)

		# If sum of the nodes on the left and the current node
		# is equal to the sum of the nodes on the right
		if current_sum == remaining_sum:
			return curr_node.data
		current_sum+= curr_node.data
		curr_node = curr_node.next
	
	return -1

# Driver code
if __name__=='__main__':
	head = None
	head = push(head, 3)
	head = push(head, 6)
	head = push(head, 1)
	head = push(head, 10)
	head = push(head, 7)
	head = push(head, 2)
	head = push(head, 1)

	print(findBalancedNode(head))
