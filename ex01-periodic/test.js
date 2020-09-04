
function z_function(s) {
    var n = s.length;
    var z = Array(n).fill(0);
    var i, l, r;
    //for our task we need only a half of z-array
    for (i = 1, l = 0, r = 0; i <= n/2; ++i) {
        if (i <= r)
            z[i] = Math.min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        //we can check condition and return here
        if (z[i] + i === n && n % i === 0) return true;

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return false;
    //return z.some((zi, i) => (i + zi) === n && n % i === 0);
}
console.log(z_function("abacabacabac"));
console.log(z_function("abcab"));
