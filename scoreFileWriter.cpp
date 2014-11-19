#include "scoreFileWriter.h"

using std::string;
using std::ostringstream;
using gameutil::FileWriter;
using gamesystem::GameInformation;
using gamesystemIO::ScoreFile;
using gamesystemIO::ScoreFileWriter;

ScoreFileWriter::ScoreFileWriter(const char* fileName) : FileWriter(fileName) {
}

ScoreFileWriter::~ScoreFileWriter(void) {
}

void ScoreFileWriter::write(ScoreFile& scoreFile) {
	ostringstream out;
	for (int i = 0; i <= gameutil::LASTSTAGE; i++) {
		for (int j = 0; j < GameInformation::STAGE_TYPE_SIZE; j++) {
			for (int k = 0; k < GameInformation::PLAYER_TYPE_SIZE; k++) {
				ScoreStock* scoreStock = scoreFile.getScoreStock(i, j, k);
				if (scoreStock == 0)
					continue;
				for (int l = 0; l < gameutil::SAVERANKSIZE; l++) {
					string name = scoreStock->getScore(l).getName();
					int score = scoreStock->getScore(l).getScore();
					if (name == "")
						name = "NONAME";
					if (score != 0)
						out << i << ' ' << j << ' ' << k << ' ' << name << ' ' << score << '\n';
				}
			}
		}
	}
	out << ":END\n";
	FileWriter::write(out.str());
}