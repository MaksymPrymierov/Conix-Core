#include <tty.h>

tty::tty()
{
        memory = reinterpret_cast<u16*>(memory_address);
        clear();
}

void tty::clear()
{
	for (size_t i = 0; i < capacity; ++i) {
                buffer[i] = 0;
	}

        update();
}

void tty::update()
{
        for (size_t i = 0; i < capacity; ++i) {
                memory[i] = buffer[i];
	}
}

void tty::print_string(const char *string)
{
      /*  for (size_t i = 0; i < strlen(message); ++i) {
                switch (message[i]) {
                case '\n':
			cursor = (cursor / TEXT_GRAPHIC_WIDTH + 1) * TEXT_GRAPHIC_WIDTH;
                        break;
		case '\b':
			--cursor;
			video_buffer[cursor] = ' ';
			break;
                default:
                        if (cursor >= TEXT_GRAPHIC_CAPACITY) {
                                scroll_down();
                        }
                        video_buffer[cursor] = TEXT_GRAPHIC_COLOR + message[i];
                        ++cursor;
                }
        } */
}
