# TO-DO:
## Features
* Structured data output like json or something.
* Asynchronous logs. Try generating logs with 5M+ logs/s.

## Bugs/Fixes
* Right now, there is a bug where if we give ```enableFileLogging(fileName)``` without the append_logs flag then it will default filename to parrot.log.

## Refact
* I'm not sure whether the name Config suits the Parrot configuration. If any better naming and refactoring for most of the things come to mind. Implement it.
* Try to make the ```#include <parrot.h>``` into ```#include <parrot>``` if possible.
