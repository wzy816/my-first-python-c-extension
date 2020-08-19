long long fac(long n) {
  if (n < 2)
    return (1);
  return (n)*fac(n - 1);
}
