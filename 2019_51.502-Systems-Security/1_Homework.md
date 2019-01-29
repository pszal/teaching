## Homework

### Exercise 1

The class presented below provides an authentication mechanisms based on password checking. What security principles are violated? Can you recover the password without accessing `_passwd` directly (if so, write code that demonstrates it)? Can you fix the method?

<pre>
import os
import random

class BlackBox(object):
    def __init__(self):
        len_ = random.randint(100, 1000)
        self._passwd = os.urandom(len_)
    
    def check(self, user_passwd):
        if len(user_passwd) != len(self._passwd):
            return "Error:len"
        for i in range(len(user_passwd)):
            if user_passwd[i] != self._passwd[i]:
                return "Error:idx:%d" % i
        return "OK"
</pre>


### Exercise 2

Write an application that executed by any Linux user will print its password's hash from `/etc/shadow`.
(See `man shadow` and Python's `os` package. For compiling a `.py` file to binary you may use `nuitka`.)


### Exercise 3

Let's assume that you have to host multiple instances of an untrusted application (an HTTP server) in Linux.

1. Conduct threat modeling.
2. Design and implement a secure Linux execution environment for this application. Each design decision relate to security principle(s) and your threat model.

Helpful resources:

- Threat Modeling Cheat Sheet
https://www.owasp.org/index.php/Threat_Modeling_Cheat_Sheet
- Chmod:
https://www.howtoforge.com/tutorial/linux-chmod-command/
- Chroot:
https://help.ubuntu.com/community/BasicChroot
https://www.tecmint.com/restrict-ssh-user-to-directory-using-chrooted-jail/
- Ulimit:
https://www.poftut.com/linux-ulimit-command-tutorial-examples-increase-open-file-limit/
http://geekswing.com/geek/quickie-tutorial-ulimit-soft-limits-hard-limits-soft-stack-hard-stack/
- Selinux:
https://linode.com/docs/quick-answers/linux/install-selinux-on-ubuntu/ 
- capabilities:
http://manpages.ubuntu.com/manpages/zesty/man7/capabilities.7.html
- Apparmor:
https://help.ubuntu.com/lts/serverguide/apparmor.html
- Firejail:
https://www.linux.com/learn/lock-your-untrusted-applications-firejail
- Docker:
https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04
- mbox:
https://github.com/tsgates/mbox/blob/master/doc/slides.pdf
