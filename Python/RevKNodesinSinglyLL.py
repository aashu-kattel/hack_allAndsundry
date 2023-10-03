# Python implementation of the approach

# Node class
class Node:
	
	# Function to initialise the node object
	def __init__(self, data):
		self.data = data # Assign data
		self.next = None
		
head = None

# Function to reverse alternate k nodes and
# return the pointer to the new head node
def kAltReverse(head, k):
	
	prev = None
	curr = head
	temp = None
	tail = None
	newHead = None
	join = None
	t = 0

	# Traverse till the end of the linked list
	while (curr != None) :
	
		t = k
		join = curr
		prev = None

		# Reverse alternative group of k nodes
		# of the given linked list
		while (curr != None and t > 0):
			
			t = t - 1
			temp = curr.next
			curr.next = prev
			prev = curr
			curr = temp
		
		# Sets the new head of the input list
		if (newHead == None):
			newHead = prev

		# Tail pointer keeps track of the last node
		# of the k-reversed linked list. The tail pointer
		# is then joined with the first node of the
		# next k-nodes of the linked list
		if (tail != None):
			tail.next = prev

		tail = join
		tail.next = curr

		t = k

		# Traverse through the next k nodes
		# which will not be reversed
		while (curr != None and t > 0):
			t = t - 1
			prev = curr
			curr = curr.next
		
		# Tail pointer keeps track of the last
		# node of the k nodes traversed above
		tail = prev
	
	# newHead is new head of the modified list
	return newHead

# Function to insert a node at
# the head of the linked list
def push(head_ref, new_data):
	
	global head
	
	# allocate node
	new_node = Node(0)

	# put in the data
	new_node.data = new_data

	# link the old list of the new node
	new_node.next = head_ref

	# move the head to point to the new node
	head_ref = new_node
	head = head_ref

# Function to print the linked list
def printList(node):

	count = 0
	while (node != None):
	
		print(node.data ,end= " ")
		node = node.next
		count = count + 1
	
# Driver code

# Start with the empty list
head = None
i = 10

# Create a list 1->2->3->4->...->10
while ( i > 0 ):
	push(head, i)
	i = i - 1

k = 3

print("Given linked list ")
printList(head)
head = kAltReverse(head, k)

print("\n Modified Linked list ")
printList(head)

# This code is contributed by Arnab Kundu
