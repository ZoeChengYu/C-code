#include <stdio.h>
#include <string.h>

#define TEAM_COUNT 3
#define TEAM_NAME_LEN 2

typedef struct {
    char name[TEAM_NAME_LEN + 1];
    int wins;
    int total_score;
} Team;

int find_team_index(Team teams[], char *name) {
    for (int i = 0; i < TEAM_COUNT; i++) {
        if (strcmp(teams[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int M;
    scanf("%d", &M);
    
    Team teams[TEAM_COUNT] = { {"A", 0, 0}, {"B", 0, 0}, {"C", 0, 0} };
    
    for (int i = 0; i < M; i++) {
        char team1[TEAM_NAME_LEN + 1], team2[TEAM_NAME_LEN + 1];
        int score1 = 0, score2 = 0;
        
        scanf("%s %s", team1, team2);
        
        for (int j = 0; j < 4; j++) {
            int s1, s2;
            scanf("%d %d", &s1, &s2);
            score1 += s1;
            score2 += s2;
        }
        
        int index1 = find_team_index(teams, team1);
        int index2 = find_team_index(teams, team2);
        
        teams[index1].total_score += score1;
        teams[index2].total_score += score2;
        
        if (score1 > score2) {
            teams[index1].wins++;
        } else {
            teams[index2].wins++;
        }
    }
    
    Team *winner = &teams[0];
    for (int i = 1; i < TEAM_COUNT; i++) {
        if (teams[i].wins > winner->wins) {
            winner = &teams[i];
        }
    }
    
    printf("%s %d\n", winner->name, winner->total_score);
    return 0;
}
