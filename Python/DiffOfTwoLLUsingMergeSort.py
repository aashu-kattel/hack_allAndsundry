# Python implementation to create
# a difference Linked List of
# two Linked Lists

# Node of the Linked List
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# Linked List
class linked_list:
	def __init__(self):
		self.head = None
	
	# Function to insert a node
	# at the end of Linked List
	def append(self, data):
		temp = Node(data)
		if self.head == None:
			self.head = temp
		else:
			p = self.head
			while p.next != None:
				p = p.next
			p.next = temp

	# Function to find the middle
	# node of the Linked List
	def get_mid(self, head):
		if head == None:
			return head
		slow = fast = head
		while fast.next != None \
		and fast.next.next != None:
			slow = slow.next
			fast = fast.next.next
		return slow

	# Recursive method to merge the
	# two half after sorting
	def merge(self, l, r):
		if l == None:return r
		if r == None:return l

		if l.data<= r.data:
			result = l
			result.next = \
				self.merge(l.next, r)
		else:
			result = r
			result.next = \
				self.merge(l, r.next)
		return result

	# Recursive method to divide the
	# list into two half until 1 node left
	def merge_sort(self, head):
		if head == None or head.next == None:
			return head
		mid = self.get_mid(head)
		next_to_mid = mid.next
		mid.next = None
		left = self.merge_sort(head)
		right = self.merge_sort(next_to_mid)
		sorted_merge = self.merge(left, right)
		return sorted_merge

	# Function to print the list elements
	def display(self):
		p = self.head
		while p != None:
			print(p.data, end =' ')
			p = p.next
		print()

# Function to get the difference list
def get_difference(p1, p2):
	difference_list = linked_list()
	# Scan the lists
	while p1 != None and p2 != None:
		
		# Condition to check if the
		# Data of the both pointer are
		# same then move ahead
		if p2.data == p1.data:
			p1 = p1.next
			p2 = p2.next
		
		# Condition to check if the
		# Data of the first pointer is
		# greater than second then
		# move second pointer ahead
		elif p2.data<p1.data:
			p2 = p2.next
		
		# Condition when first pointer
		# data is greater than the
		# second pointer then append
		# into the difference list and move
		else:
			difference_list.append(p1.data)
			p1 = p1.next

	# If end of list2 is reached,
	# there may be some nodes in
	# List 1 left to be scanned,
	# they all will be inserted
	# in the difference list
	if p2 == None:
		while p1:
			difference_list.append(p1.data)
			p1 = p1.next

	return difference_list

# Driver Code
if __name__ == '__main__':
	# Linked List 1
	list1 = linked_list()
	list1.append(2)
	list1.append(6)
	list1.append(8)
	list1.append(1)
	
	# Linked List 2
	list2 = linked_list()
	list2.append(4)
	list2.append(1)
	list2.append(9)
	
	# Sort both the linkedlists
	list1.head = list1.merge_sort(
				list1.head
				)
	list2.head = list2.merge_sort(
				list2.head
				)
	
	# Get difference list
	result = get_difference(
			list1.head, list2.head
			)
	if result.head:
		result.display()
	
	# if difference list is empty,
	# then lists are equal
	else:
		print('Lists are equal')
