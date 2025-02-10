#ifndef DOCLI_H
#define DOCLI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Main structure for docli commands. */
typedef struct {
	const char *cmd_name;
	const char *cmd_description;
	void (*const cmd_func)(int argc, char *argv[]);
} docli_cmd_t;

/* Initialisation of peripheral device for communication - user must define. */
void docli_init(void);
/* Put character to peripheral device for communication - user must define. */
void docli_putchar(char chr);
/* Get character from peripheral device for communication - user must define. */
char docli_getchar(void);

/* Add user commands to docli. */
void docli_add_user_cmds(const docli_cmd_t *cmds, unsigned cmds_num);
/* Add user commands to docli (to be executed quickly after boot). */
void docli_add_user_auto_cmds(const docli_cmd_t *cmds, unsigned cmds_num);
/* Main pooling loop of docli. */
void docli_poll(void);

/* TODO: need code here. */

#ifdef __cplusplus
}
#endif

#endif /* DOCLI_H */
