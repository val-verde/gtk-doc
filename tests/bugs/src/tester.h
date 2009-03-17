#ifndef GTKDOC_TESTER_H
#define GTKDOC_TESTER_H

#include <glib.h>

/**
 * bug_324535:
 * @BUG_324535_A: enum 1
 * @BUG_324535_B: enum 2
 * @BUG_324535_C: enum 3
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=324535
 */
typedef enum {
  BUG_324535_A,
#ifdef GTK_DISABLE_DEPRECATED
  BUG_324535_B,
#endif
  BUG_324535_C,
} bug_324535;


/**
 * bug_501038:
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=501038
 */
struct _bug_501038 {
  gint a;
#ifdef GTK_DISABLE_DEPRECATED
  gint b;
#else
  gint _b;
#endif
};


#define _PADDDING 4
/**
 * bug_460127:
 * @a: field
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=460127
 */
struct _bug_460127 {
  /*< public >*/
  gint a;

  /*< private >*/
  union {
    struct {
      gint b;
    } ABI;
    gpointer _reserved[_PADDDING + 0];
  } abidata;

};


/**
 * bug_477532:
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=477532
 */
GLIB_VAR guint64 (*bug_477532) (void);


struct bug {
  int test;
};


void bug_141869_a (unsigned pid);
void bug_141869_b (signed pid);

void bug_379466 (int
  pid);

int bug_380824 (int arg);

struct bug *
bug_411739 (void);

void bug_419997 (int const_values);

void bug_445693 (unsigned long pid);

G_CONST_RETURN gchar* G_CONST_RETURN *
bug_471014 (void);

const char* const * bug_552602 (void);

/**
 * Bug446648:
 * @BUG_446648_FOO: field
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=446648
 */
typedef enum _Bug446648 Bug446648;
enum _Bug446648 {
    BUG_446648_FOO
};

/**
 * Bug512154:
 * @index: field
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=512154
 */
typedef struct {
  unsigned long index;
} Bug512154;

/**
 * BUG_530758:
 *
 * <![CDATA[http://bugzilla.gnome.org/show_bug.cgi?id=530758#c1]]>
 * 
 * <ulink url="http://bugzilla.gnome.org/show_bug.cgi?id=530758#c1">Test</ulink>
 */
#define BUG_530758 "dummy"


/**
 * bug_532395a:
 * @number: a number
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=532395
 *
 * Returns: number
 */
/**
 * bug_532395b:
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=532395
 */
G_INLINE_FUNC guint
bug_532395a (gulong number)
{
#if defined(__GNUC__) && (__GNUC__ >= 4) && defined(__OPTIMIZE__)
  return G_LIKELY (number) ?
	   ((GLIB_SIZEOF_LONG * 8 - 1) ^ __builtin_clzl(number)) + 1 : 1;
#else
  return 0;
#endif
}
G_INLINE_FUNC void
bug_532395b (void)
{
}


/** 
 * bug_544172:
 * @self: object pointer.
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=544172
 *
 * Returns: result or %NULL.
 */
typedef char const * (*bug_544172) (char const *self);


/** 
 * bug_554833:
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=554833
 */
struct _bug_554833 {
  int i;
};


/** 
 * bug_554833_new:
 *
 * http://bugzilla.gnome.org/show_bug.cgi?id=554833
 *
 * Returns: result
 */
struct _bug_554833 *
                bug_554833_new (void);

#define GTKDOC_GNUC_CONST
int bug_574654a(void) GTKDOC_GNUC_CONST;
void bug_574654b(double offset);


#endif // GTKDOC_TESTER_H

