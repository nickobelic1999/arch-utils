
// Pull from: https://askubuntu.com/questions/80254/how-do-i-turn-off-caps-lock-the-lock-not-the-key-by-command-line
// Altered by Nicholas White

#include <iostream>
#include <unistd.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/XKBlib.h>

int main(int argc, char* argv[])
{
    bool sent;
    Display *display = XOpenDisplay(NULL);

    if (display == NULL) {
        std::cerr << "Couldn't open display!" << std::endl;
        return 2;
    }

    sent = XkbLockModifiers(display, XkbUseCoreKbd, LockMask, 0);
    if (!sent)
    {
        std::cerr << "Couldn't send LatchLockState!" << std::endl;
        return 1;
    }

#ifdef REPORT_STATE
    XkbStateRec xkb_state;
    Status status = XkbGetState(display, XkbUseCoreKbd, &xkb_state);
    if (status) {
        std::cerr << "XkbGetState returned: " << status << std::endl;
	return 1;
    }

    std::cout << "state.group=" << xkb_state.group << std::endl;
    std::cout << "state.locked_group=" << xkb_state.locked_group << std::endl;
    std::cout << "state.base_group=" << xkb_state.base_group << std::endl;
    std::cout << "state.latched_group=" << xkb_state.latched_group << std::endl;
    std::cout << "state.mods=" << xkb_state.mods << std::endl;
    std::cout << "state.base_mods=" << xkb_state.base_mods << std::endl;
    std::cout << "state.latched_mods=" << xkb_state.latched_mod << std::endl;
    std::cout << "state.locked_mods=" << xkb_state.locked_mods << std::endl;
    std::cout << "state.compat_state=" << xkb_state.compat_state << std::endl;
    std::cout << "state.grab_mods=" << xkb_state.grab_mods << std::endl;
    std::cout << "state.compat_grab_mods=" << xkb_state.compat_grab_mods << std::endl;
    std::cout << "state.lookup_mods=" << xkb_state.lookup_mods << std::endl;
    std::cout << "state.compat_lookup_mods=" << xkb_state.compat_lookup_mods << std::endl;
    std::cout << "state.ptr_buttons=" << xkb_state.ptr_buttons << std::endl;

#endif
    int err = XCloseDisplay(display);
    if (err) {
        std::cerr << "XCloseDisplay returned: " << err << std::endl;
	return 1;
    }

    return 0;
}
