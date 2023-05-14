#include <stdio.h>
#define BUFFER_SIZE 1024

// sha-3 with 512 bit (64 chars) block will be done, so i'll make pkcs#7 padding

struct node {
  int da;
  struct node *plink;
};
typedef struct node *node;

node linked_list(int *narr, int n) {
  static int i = 0;
  node t = NULL;
  if (n != 0) {
    t = (node)malloc(sizeof(struct node *));
    t->da = narr[i++];
    t->plink = linked_list(narr, --n);
  }
  return t;
}

node go_to(node ll, int number) {
  while (number) {
    ll = ll->plink;
    number--;
  }
  return ll;
}

int fast_pow(long a, long b) {

  if (b == 1)
    return a;
  if (b % 2 == 1)
    return a * fast_pow(a, b - 1);
  int tmp_exp = fast_pow(a, b / 2);
  return tmp_exp * tmp_exp;
}

int count(int l, int x, int y, int z) {

  return fast_pow(2, l) * (5 * y + x) + z;
}

char *padding(int co, unsigned char *message, int rate) {

  unsigned char padded_message[rate * (co / rate + 1)];
  int needed = rate - co % rate;
  for (int i = co; i < co + needed; i++) {

    padded_message[i] = (unsigned char)needed;
  }
}

void pi(node S, int x, int y, int z, int l) {

  go_to(S, count(l, x, y, z))->da =
      go_to(S, count(l, (x + 3 * y) % 5, x, z))->da;
  // S[count(l, x, y, z)] = S[count(l, (x + 3 * y) % 5, x, z)];
}

void rho(node S, int x, int y, int z, int l) {

  int w = fast_pow(2, l);
  for (int t = 0; t < 24; t++) {

    if (z < w) {

      go_to(S, count(l, x, y, z))->da =
          go_to(S, count(l, x, y, (z - (t + 1) * (t + 2) / 2) % w))->da;
    }
  }
}

int sum(node S, int x, int y, int z, int l) {

  int co = 0;
  for (int i = 0; i < 5; i++) {

    co += go_to(S, count(l, x, i, z))->da;
  }
  return co;
}

void theta(node S, int x, int y, int z, int l) {

  go_to(S, count(l, x, y, z))->da +=
      sum(S, x - 1, y, z, l) + sum(S, x + 1, y, z, l);
}

void chi(node S, int x, int y, int z, int l) {

  go_to(S, count(l, x, y, z))->da =
      go_to(S, count(l, x, y, z))->da ^ 1 ^
      go_to(S, count(l, (x + 1) % 5, y, z))->da *
          go_to(S, count(l, (x + 2) % 5, y, z))->da;
}

int main() {

  int b = 1600; // to be set. Should be b / 8 cuz will be used as for bytes, not
                // bits
  int r = 576;  // to be set. Same
  int c = b - r; // capacity
  int l = 6;     // 2^l word length
  unsigned char message[512];
  scanf("%s", message);
  int size = fast_pow(2, l) * 5 * 5;
  char a = 'q';
  int co = 0;
  while (a != '\0') {

    a = message[co];
    co++;
  }
  unsigned char padded_message[co + r - co % r] = padding(co, message, r);
  int ar[size] = {0};
  node S = linked_list(ar, size); // state
}