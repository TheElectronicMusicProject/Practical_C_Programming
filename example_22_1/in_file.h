#ifndef IN_FILE_H
#define IN_FILE_H

extern int in_open(const char name[]);
extern void in_close(void);
extern void in_read_char(void);
extern int in_cur_char(void);
extern int in_next_char(void);
extern void in_flush(void);

#endif /* IN_FILE_H */