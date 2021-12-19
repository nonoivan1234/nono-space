a = 123
b = 456
c = 'is not equal to'
# We want to print '123is not equal to456'

# Original
print(str(a)+c+str(b))

# Format String
print(f'{a}{c}{b}')