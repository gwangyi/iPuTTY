/*
 * Linking module for PuTTY proper: list the available backends
 * including ssh, plus the serial backend.
 */

#include <stdio.h>
#include "putty.h"

/*
 * This appname is not strictly in the right place, since Plink
 * also uses this module. However, Plink doesn't currently use any
 * of the dialog-box sorts of things that make use of appname, so
 * it shouldn't do any harm here. I'm trying to avoid having to
 * have tiny little source modules containing nothing but
 * declarations of appname, for as long as I can...
 */
const char *const appname = "iPuTTY";

#ifdef TELNET_DEFAULT
const int be_default_protocol = PROT_TELNET;
#else
const int be_default_protocol = PROT_SSH;
#endif

Backend *backends[] = {
    &ssh_backend,
    &telnet_backend,
    &rlogin_backend,
    &raw_backend,
    &serial_backend,
#ifdef SUPPORT_CYGTERM
    &cygterm_backend,
#endif
    NULL
};

// vim: ts=8 sts=4 sw=4 noet cino=\:2\=2(0u0
