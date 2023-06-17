/*
 *  This file is part of android-tree-sitter.
 *
 *  android-tree-sitter library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  android-tree-sitter library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *  along with android-tree-sitter.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.itsaky.androidide.treesitter;

/**
 * @author Akash Yadav
 */
public class TSQueryCursor extends TSNativeObject {

  public TSQueryCursor() {
    super(Native.newCursor());
  }

  /** Start running the given query on the given node. */
  public void exec(TSQuery query, TSNode node) {
    checkAccess();
    if (query == null || !query.canAccess()) {
      throw new IllegalArgumentException("Cannot execute invalid query");
    }
    Native.exec(this.pointer, query.pointer, node);
  }

  /**
   * Whether the maximum number of in-progress matches allowed by this query cursor has been
   * exceeded or not.
   *
   * <p>Query cursors have an optional maximum capacity for storing lists of in-progress captures.
   * If this capacity is exceeded, then the earliest-starting match will silently be dropped to make
   * room for further matches. This maximum capacity is optional — by default, query cursors allow
   * any number of pending matches, dynamically allocating new space for them as needed as the query
   * is executed.
   */
  public boolean didExceedMatchLimit() {
    checkAccess();
    return Native.exceededMatchLimit(this.pointer);
  }

  /**
   * Get the maximum number of in-progress matches allowed by this query * cursor.
   *
   * @return The match limit.
   * @see #didExceedMatchLimit()
   */
  public int getMatchLimit() {
    checkAccess();
    return Native.matchLimit(this.pointer);
  }

  /**
   * Set the maximum number of in-progress matches allowed by this query * cursor.
   *
   * @param newLimit The new match limit.
   * @see #didExceedMatchLimit()
   */
  public void setMatchLimit(int newLimit) {
    checkAccess();
    Native.matchLimit(this.pointer, newLimit);
  }

  public void setByteRange(int start, int end) {
    checkAccess();
    Native.setByteRange(this.pointer, start, end);
  }

  public void setPointRange(TSPoint start, TSPoint end) {
    checkAccess();
    Native.setPointRange(this.pointer, start, end);
  }

  public TSQueryMatch nextMatch() {
    checkAccess();
    return Native.nextMatch(this.pointer);
  }

  public void removeMatch(int id) {
    checkAccess();
    Native.removeMatch(this.pointer, id);
  }

  @Override
  protected void closeNativeObj() {
    Native.delete(this.pointer);
  }

  private static class Native {
    public static native long newCursor();

    public static native void delete(long cursor);

    public static native void exec(long cursor, long query, TSNode node);

    public static native boolean exceededMatchLimit(long cursor);

    public static native void matchLimit(long cursor, int newLimit);

    public static native int matchLimit(long cursor);

    public static native void setByteRange(long cursor, int start, int end);

    public static native void setPointRange(long cursor, TSPoint start, TSPoint end);

    public static native TSQueryMatch nextMatch(long cursor);

    public static native void removeMatch(long cursor, int id);
  }
}