#ifndef BALANCING_HEADER
#define BALANCING_HEADER


int balanced(char *data);
int match(char x, char y);
void missingClosingCharacterError(char c);
void missingOpeningCharacterError(char c);
void missingOpeningCommentError();
void missingClosingCommentError();
void validInputSuccess();

#endif