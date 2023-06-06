#include <iostream>
#include <cstring>
#include "Movie.h"
#include "File.h"

using namespace std; // not allowed in a ".h" file

namespace sdds {

    Movie movies[50]; //같은 공간에 있는 함수들이 접근가능(클래스), 이미 데이터가 들어가 있음.

    // loads all the moves into the global array of structures.
    bool loadMovies() {
        Movie mv;
        int mnum = 0; // number of movies read
        bool ok = true;
        if (openFile("movies.dat")) {
            while (ok && mnum < 50) {
                ok = readTitle(mv.m_title) &&
                    readYear(&mv.m_year) &&
                    readMovieRating(mv.m_rating) &&
                    readDuration(&mv.m_duration) &&
                    readGenres(mv.m_genres) &&
                    readConsumerRating(&mv.m_consumerRating);
                if (ok) movies[mnum++] = mv;
            }
            closeFile();
        }
        return mnum == 50;
    }

    // returns true is the genre arg is substring of any of the
    // genres of the target of the mvp (Movie*) arg.
    bool hasGenre(const Movie* mvp, const char genre[]) { //for GPAlist
        int i = 0;
        bool found = false;
        while (!found && mvp->m_genres[i][0]) { //장르의 갯수(앞자리배열)만큼 반복. i번째의 첫번째캐릭터(뒷자리 배열)가 널일때 까지
            if (strstr(mvp->m_genres[i++], genre)) { //str1과 str2를 비교하여 일치하는 문자열이 있는지 확인하는 함수. 일치하는 문자열이 있으면 해당 위치의 포인터(char* 타입)를 반환. 일치하는 문자열을 찾지 못하면 null pointer를 반환.
                found = true;
            }
        }
        return found;
    }

    // displays the movie info
    void displayMovie(const Movie* mvp) { //for list
        int i = 1;
        cout << mvp->m_title << " [" << mvp->m_year << "], "
            << mvp->m_rating << ", duration: " << mvp->m_duration << " minutes, Rating: " << mvp->m_consumerRating << "/10" << endl << "    (" << mvp->m_genres[0]; //장르하나는 무조건 존재하기 때문에 무조건 출력
        while (mvp->m_genres[i][0]) { //두번째 자리에 값이 있으면 출력
            cout << ", " << mvp->m_genres[i++];
        }
        cout << ")" << endl;
    }

    // displays all the movies containing the genre arg
    void displayMoviesWithGenre(const char genre[]) { //for list
        int i, j;
        for (i = 0, j = 1; i < 50; i++) {
            if (hasGenre(&movies[i], genre)) { //무비 클래스에서 사용자 입력값과 하나씩 스트링비교
                cout << j++ << "- ";
                displayMovie(&movies[i]);
            }
        }
        if (j == 1) {
            cout << "No match found for: " << genre << endl;
        }
    }

}
