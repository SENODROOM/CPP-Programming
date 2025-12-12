#ifndef SETTINGS_H
#define SETTINGS_H

extern int soundOn;
extern int theme; // 0 default, 1 alternate

void loadSettings(const char* filename);
void saveSettings(const char* filename);

#endif // SETTINGS_H
