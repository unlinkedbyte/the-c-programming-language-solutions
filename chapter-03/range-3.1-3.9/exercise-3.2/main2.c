/* I always correct my code with the AI before uploading it. 
 * I wanted to leave this one here as a log as well, to see the different options available 
 * in the future. I didn't make this one; AI suggested it after saying that the exercise strictly 
 * required the switches, but I don't want to put a pasted code that maybe I don't understand 100%. 
 * Both, theoretically, are valid and safe.
 */

void unescape(char s[], char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
            case '\\':
                switch (t[i + 1]) {
                    case 'n':
                        s[j++] = '\n';
                        i++;
                        break;
                    case 't':
                        s[j++] = '\t';
                        i++;
                        break;
                    default:
                        s[j++] = '\\';
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0';
}

