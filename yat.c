#include <stdio.h>
#include <string.h>
#include <fts.h>

void ident(short level);
int tree(char **paths);

int main(int argc, char **argv) {
	char **paths, *path[] = {".", 0};
	if(argc >= 2) {
		paths = argv + 1;
		for(int i = 0; i < argc - 1; i++) {
			size_t len = strlen(paths[i]) - 1;
			if(len > 1 && paths[i][len] == '/')
				paths[i][len] = 0;
		}
	}
	else
		paths = path;
	return tree(paths);
}

void ident(short level) {
	level *= 2;
	for(;level--;)
		putchar(' ');
}

int tree(char **paths) {
	FTS *fts = fts_open(paths, FTS_COMFOLLOW | FTS_LOGICAL | FTS_NOSTAT, 0);
	if(!fts)
		return 1;
	size_t ndir = 0, nfile = 0;
	FTSENT *file;
	while((file = fts_read(fts))) {
		if(file->fts_info == FTS_ERR)
			return 1;
		if(file->fts_namelen >= 2 && file->fts_name[0] == '.' && file->fts_name[1] != '.') {
			fts_set(fts, file, FTS_SKIP);
			continue;
		}
		switch(file->fts_info) {
			case FTS_D:
				if(file->fts_level != 0)
					ndir++;
				else if(ndir >= 1)
					putchar('\n');
				ident(file->fts_level);
				printf("%s/\n", file->fts_name);
				break;
			case FTS_F:
				nfile++;
				ident(file->fts_level);
				puts(file->fts_name);
				break;
		}
	}
	fts_close(fts);
	printf("\n%zu director%s, %zu file%s\n", ndir, ndir == 1 ? "y" : "ies", nfile, nfile == 1 ? "" : "s");
	return 0;
}
