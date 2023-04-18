-- This program will print its own source when run.
local Colleen = "-- This program will print its own source when run.%clocal Colleen = %q%c%c-- This program will print its own source when run.%cio.write(string.format(Colleen, 10, Colleen, 10, 10, 10))"

-- This program will print its own source when run.
io.write(string.format(Colleen, 10, Colleen, 10, 10, 10))