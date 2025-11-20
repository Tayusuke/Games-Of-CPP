# include <Siv3D.hpp> // Siv3D v0.6.16

Color lerper(Circle& it) {
	Color current_color = current_color.lerp(it.mouseOver() ? Palette::Lightgray : Palette::White, 0.2);

	return current_color;
}

void Main() {
	Window::SetTitle(U"The Clicker Game");
	Scene::SetBackground(Palette::Skyblue);

	Circle clickButton{ Vec2{500, 400}, 80 };

	RoundRect shopButton{ Arg::center(600, 80), 250, 125, 20 };
	RoundRect shopUI{ Arg::center(400, 380), 530, 400, 20 };

	//アップグレード系ボタン
	Circle UpPoint{ Vec2{250, 260}, 60 };
	Circle AutoClick{ Vec2{550, 260}, 60 };
	Circle Rebirth{ Vec2{400, 400}, 60 };

	int point = 0;

	Font text_Font(50);

	Font clickFont_big(37);
	Font clickFont_small(29);

	Font small(20);

	Color click_current;
	Color shop_current;

	const Color black = Palette::Black;

	const Color defaultColor = Palette::White;
	const Color hoverColor = Palette::Lightgray;

	bool isShopUIOpen = false;

	int upNumber = 1;
	int autoNumber = 0;
	int rebirthNumber = 1;

	Stopwatch autowatch{ StartImmediately::Yes };

	while (System::Update()) {
		// マウスがホバーしているかを判定
		bool isClickHovered = clickButton.mouseOver();
		bool isShopHovered = shopButton.mouseOver();

		// クリックしてポイント加算
		if (clickButton.leftClicked() && !isShopUIOpen) {
			point += upNumber * rebirthNumber;
		}

		if (autowatch.isRunning()) {
			if (autowatch.s() >= 1) {
				point += autoNumber * rebirthNumber;
				autowatch.restart();
			}
		}

		//マウスの位置によってボタンの色変更
		click_current = click_current.lerp(isClickHovered ? hoverColor : defaultColor, 0.2);
		shop_current = shop_current.lerp(isShopHovered ? hoverColor : defaultColor, 0.2);

		//ボタンを描画
		clickButton.draw(click_current);
		clickButton.drawFrame(5, black);

		//ショップのボタンを描画
		shopButton.draw(shop_current);
		shopButton.drawFrame(5, black);

		//アップグレードボタンを押したか
		if (shopButton.leftClicked()) {
			isShopUIOpen = !isShopUIOpen;
		}

		//ボタンとフォントクリックしたら小っちゃく
		if (clickButton.leftPressed() && !isShopUIOpen) {
			clickFont_small(U"Click!!!").drawAt(clickButton.center, black);
			clickButton.r = 65;
		}
		else {
			clickFont_big(U"Click!!!").drawAt(clickButton.center, black);
			clickButton.r = 80;
		}

		//アップグレードUI描画
		if (isShopUIOpen) {
			shopUI.draw(Palette::White);
			shopUI.drawFrame(10, black);
			text_Font(U"Quit").drawAt(Vec2{ 600, 80 }, black);

			//ポイント増加のボタン描画/処理
			UpPoint.draw(lerper(UpPoint));
			UpPoint.drawFrame(6, black);
			small(U"need 10point").drawAt(Vec2{ 250, 350 }, black);
			small(U"increase : {} < {}"_fmt(upNumber, upNumber + 1)).drawAt(Vec2{ 250, 400 }, black);

			if (UpPoint.leftClicked()) {
				if (point >= 10) {
					upNumber += 1;
					point -= 10;
				}
			}

			//自動クリックのボタン描画/処理
			AutoClick.draw(lerper(AutoClick));
			AutoClick.drawFrame(6, black);
			small(U"need 80point").drawAt(Vec2{ 550, 350 }, black);
			small(U"increase : {} < {}"_fmt(autoNumber, autoNumber + 1)).drawAt(Vec2{ 550, 400 }, black);

			if (AutoClick.leftClicked()) {
				if (point >= 80) {
					autoNumber += 1;
					point -= 80;
				}
			}

			//リバースボタン描画/処理
			Rebirth.draw(lerper(Rebirth));
			Rebirth.drawFrame(6, black);
			small(U"need {}point"_fmt(10000 * rebirthNumber)).drawAt(Vec2{ 400, 480 }, black);
			small(U"rebirth multiplier : {} < {}"_fmt(rebirthNumber, rebirthNumber + 1))
				.drawAt(Vec2{ 400, 530 }, black);

			if (Rebirth.leftClicked()) {
				if (point >= 10000 * rebirthNumber) {
					point = 0;
					rebirthNumber += 1;
					upNumber = 1;
					autoNumber = 0;
				}
			}
		}
		else {
			//UIの状況によってテキストも変更
			text_Font(U"Upgrade").drawAt(Vec2{ 600, 80 }, black);
		}

		// スコアを描画
		text_Font(U"point : {}"_fmt(point)).drawAt(Vec2{ 140, 80 }, black);
	}
}
