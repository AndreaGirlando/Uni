/**
 *  raccoglie e visualizza tutta una serie di informazioni su
 *  un oggetto del file-system specificato sulla riga di comando
 */

#include "lib-misc.h"
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat statbuf;
    struct passwd *pw;
    struct group *gr;
    const char *username, *groupname;
    const char *type;
    mode_t modes;

    if (argc < 2)
        exit_with_err_msg("utilizzo: %s <pathname>\n", argv[0]);

    // raccoglie le informazioni sull'oggetto
    if (lstat(argv[1], &statbuf) == -1)
        exit_with_sys_err(argv[1]);

    // prende il nome del proprietario
    if ((pw = getpwuid(statbuf.st_uid)) == NULL)
        username = "????";
    else
        username = pw->pw_name;

    // prende il nome del gruppo
    if ((gr = getgrgid(statbuf.st_gid)) == NULL)
        groupname = "????";
    else
        groupname = gr->gr_name;

    // determina il tipo dell'oggetto su file-system
    modes = statbuf.st_mode;
    if (S_ISDIR(modes))
        type = "directory";
    else if (S_ISBLK(modes) || S_ISCHR(modes))
        type = "file speciale di dispositivo";
    else if (S_ISREG(modes))
        type = "file regolare";
    else if (S_ISLNK(modes))
        type = "link simbolico";
    else if (S_ISFIFO(modes))
        type = "file FIFO";
    else
        type = "--indefinito (!?!)--";

    // stampa alcune informazioni
    printf("filename: %s\n", argv[1]);
    printf("permissions: %o\n", modes & 0777);
    printf("type: %s\n", type);
    printf("size: %lu\n", statbuf.st_size);
    printf("i-number: %d\n", (int)statbuf.st_ino);
    printf("uid: %d (%s) gid: %d (%s)\n", statbuf.st_uid, username,
           statbuf.st_gid, groupname);
    printf("atime: %s", asctime(localtime(&(statbuf.st_atime))));
    printf("mtime: %s", asctime(localtime(&(statbuf.st_mtime))));
    printf("ctime: %s", asctime(localtime(&(statbuf.st_ctime))));

    exit(EXIT_SUCCESS);
}
