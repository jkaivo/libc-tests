This is a small set of unit tests for an ISO/IEC 9899 conformant C library.

To build, edit `config.mk` with the appropriate compiler and flags to link
the library you are testing. The run `make` to get the executable `testlibc`.
Note that the source files depend on your compiler predefinining
__STDC_VERSION__ appropriately to determine which tests to include. The
default `config.mk` is configured for testing the UNGOL C library, which is
probably not what you want.

By default, running `testlibc` will run tests for all headers found during
compilation, with the exception of <assert.h> (as that test includes an
abnormal termination).

To run tests for a specified set of headers, append their base names (without
the `.h`) to the command line. For example, to run only the tests for <stdio.h>
and <stdlib.h>, run:

    testlibc stdio stdlib

Each test will print either a `+` (for success) or `-` (for failure) after it
completes. To get verbose output, where each test is displayed as well as
the results, use the `-v` option (it must come before any header names):

    testlibc -v
    testlibc -v assert
