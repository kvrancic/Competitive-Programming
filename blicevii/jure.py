# Read input values from standard input.
n, y, j = map(int, input().split())

# Read the values of xi and yi for each guest.
guests = [(int(input()), int(input())) for i in range(n)]

# Sort the guests in descending order by their xi value.
guests.sort(key=lambda x: -x[0])

# Initialize the table of maximum drink consumption values to 0.
max_drinks = [[0 for j in range(y + 1)] for i in range(n + 1)]

# Process each guest in order of their xi value.
for i in range(1, n + 1):
  x, y = guests[i - 1]

  # Process each possible value of Y.
  for j in range(y, y + 1):
    # The maximum drink consumption is the maximum of the previous value,
    # or the current value plus the maximum drink consumption for the
    # remaining capacity of Y minus the guest's yi value.
    max_drinks[i][j] = max(max_drinks[i - 1][j], max_drinks[i - 1][j - y] + x)

# The final result is the maximum drink consumption for Y capacity and
# the last guest, plus Jure's drink consumption.
result = max_drinks[n][y] + j

# Print the final result.
print(result)