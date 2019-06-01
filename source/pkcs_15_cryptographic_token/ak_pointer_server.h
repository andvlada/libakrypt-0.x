#ifndef ASN1_SECKEY_RW_POINTERSERVER_H
#define ASN1_SECKEY_RW_POINTERSERVER_H

#include "kc_includes.h"
#include <libakrypt.h>

#define PS_U_MODE 0
#define PS_R_MODE 1
#define PS_W_MODE 2

/*! \brief
 * Поля структуры s_ptr_server
 *
 * mp_begin - указатель на начало данных
 * mp_curr  - указатель на текущую позицию
 * mp_end   - указатель на первый байт после данных
 *
 * m_mode - режим использования сервера:
 *
 * 'PS_U_MODE' - сервер используется для указания границ объекта;
 * В этом режиме сервер указывает на тег, длину блока,
 * блок данных (mp_current = NULL).
 *
 * 'PS_R_MODE' - сервер используется для чтения данных;
 * В этом режиме смещение указателья на тек. позицию происходит слева направо.
 *
 * 'PS_W_MODE' - сервер используется для записи данных;
 * В этом режиме смещение указателья на тек. позицию происходит справа налево.
*/
typedef struct {
  byte* mp_begin;
  byte* mp_curr;
  byte* mp_end;
  uint8_t m_mode;
} s_ptr_server;

/*! \brief Метод для выделения памяти под объект типа s_ptr_server. */
int ps_alloc(s_ptr_server* p_ps, size_t size, uint8_t mode);
/*! \brief Метод для перевыделения памяти под объект типа s_ptr_server. */
int ps_realloc(s_ptr_server* p_ps, size_t new_size);
/*! \brief Метод для установления значений объект типа s_ptr_server. */
int ps_set(s_ptr_server* p_ps, byte* from, size_t len, uint8_t mode);
/*! \brief Метод для перемещения указателя на текующую позицию. */
int ps_move_cursor(s_ptr_server* p_ps, size_t num);
/*! \brief Метод для получения текущего размера данных. */
size_t ps_get_curr_size(s_ptr_server* p_ps);
/*! \brief Метод для получения размера памяти выделенного под объект типа s_ptr_server. */
size_t ps_get_full_size(s_ptr_server* p_ps);

#endif //ASN1_SECKEY_RW_POINTERSERVER_H
