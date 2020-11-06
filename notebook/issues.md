

run error
```
Fatal Python error: initfsencoding: unable to load the file system codec ModuleNotFoundError: No module named 'encodings'


fixed:
I ran into this same issue on Windows 10. Here's how I fixed it:

Open your 'Environment Variables' (Under 'System Properties').
In the window that opens, select the 'Path' row, then click the 'Edit...' button.
There should be two environment variables C:\Python37-32\Scripts\ and C:\Python37-32\ Then click 'OK' (Make sure to check that these path values correspond to the location and version of your Python install.)
Next, in the top portion of the 'Environment Variables' window, look for the PYTHONHOME variable and make sure that it is also set to C:\Python37-32

I can only comment on the Windows 10 issue: I think I did the install
with "Right-click -> Run as administrator" and then installed for
all users.  Encodings, pip and everything else works here.

https://bugs.python.org/issue27054

```



