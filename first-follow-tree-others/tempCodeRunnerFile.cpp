void getFollow(char ch) {
    if (isVisited.count(ch))
        return;

    isVisited.insert(ch);

    for (char left : nonTerminal) {
        for (string prod : production[left]) {
            // check every production  to find ch.

            int len = prod.size();
            bool isGet = false;
            for (int i = 0; i < len; i++) {
                if (isGet) {
                    if (isCapital(prod[i])) {
                        for (char x : first[prod[i]]) {
                            follow[ch].insert(x);
                        }

                        if (first[prod[i]].count('e'))
                            continue;
                        else
                            isGet = false;
                    } else {
                        follow[ch].insert(prod[i]);
                        isGet = false;
                    }
                    continue;
                }
                if (prod[i] == ch) {
                    isGet = true;
                }
            }
            if (isGet) {
                getFollow(left);
                for (int x : follow[left]) {
                    follow[ch].insert(x);
                }
            }
        }
    }
    follow[ch].erase('e');
}
