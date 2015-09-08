# Test-DirtyBuffer

This sample application writes to the console

* by simple `printf` from stdio
* by WriteConsoleOutputCharacter from Windows console API

So, you will not see the line written by Windows API
in terminals which do not care about it, like mintty
or ConsoleZ.

~~~
**** This is dirty line ****
~~~
