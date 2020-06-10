/* delete me */
static int my_errno;

int *__errno_location(void);
libc_hidden_proto (__errno_location)
int *__errno_location(void)
{
  return &my_errno;
}
libc_hidden_def (__errno_location)
