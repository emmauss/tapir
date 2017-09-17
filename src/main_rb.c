#include <ruby.h>
#include "main_rb.h"

#if RGSS == 3
#define RGSS_RESET "RGSSReset"
#define TERMS "Terms"
#define SCRIPT_PATH "\"Data/Scripts.rvdata2\""
#elif RGSS == 2
#define RGSS_RESET "Reset"
#define TERMS "Terms"
#define SCRIPT_PATH "\"Data/Scripts.rvdata\""
#else
#define RGSS_RESET "Reset"
#define TERMS "Words"
#define SCRIPT_PATH "\"Data/Scripts.rxdata\""
#endif

VALUE main_rb(VALUE data) {
  (void) data;
  rb_eval_string(
#if RGSS < 3
      "$KCODE = \"u\"\n"
#endif
      "module Audio\n"
      "  def self.bgm_play(path, volume, pitch)\n"
      "  end\n"
      "  def self.bgm_stop\n"
      "  end\n"
      "  def self.me_stop\n"
      "  end\n"
      "  def self.bgs_stop\n"
      "  end\n"
      "end\n"
      "class Bitmap\n"
      "  attr_accessor :font\n"
      "  def font\n"
      "    if !@font\n"
      "      @font = Font.new\n"
      "    end\n"
      "    @font\n"
      "  end\n"
      "  def clear_rect(rect)\n"
      "  end\n"
      "  def draw_text(rect, text, foo=0)\n"
      "  end\n"
      "  def fill_rect(rect, color)\n"
      "  end\n"
      "  def get_pixel(x, y)\n"
      "    Color.new(0.0, 0.0, 0.0, 0.0)\n"
      "  end\n"
      "  def clear\n"
      "  end\n"
      "  def dispose\n"
      "  end\n"
      "end\n"
      "class Font\n"
      "  attr_accessor :color, :size\n"
      "  def initialize\n"
      "    @color = Color.new(0.0, 0.0, 0.0, 0.0)\n"
      "  end\n"
      /* TODO: Font.exist? */
      "  def self.exist?(name)\n"
      "    true\n"
      "  end\n"
      "end\n"
      "module Graphics\n"
      "  def self.frame_reset\n"
      "  end\n"
      "  def self.frame_count=(count)\n"
      "  end\n"
      "  def self.transition(frames = nil)\n"
      "  end\n"
      /* TODO: Graphics.freeze */
      "  def self.freeze\n"
      "  end\n"
      "end\n"
      "class Plane\n"
      "  attr_accessor :z\n"
      "  def initialize(viewport=nil)\n"
      "  end\n"
      "end\n"
      "class Sprite\n"
      "  def update\n"
      "  end\n"
      "end\n"
      "class Tilemap\n"
#if RGSS >= 2
#else
      "  attr_accessor :autotiles, :map_data, :priorities, :tileset\n"
      "  def initialize(viewport=nil)\n"
      "    @autotiles = [nil, nil, nil, nil, nil, nil]\n"
      "  end\n"
#endif
      "end\n"

      "class Window\n"
      "  attr_accessor :active, :back_opacity, :contents, :contents_opacity, :cursor_rect, :height, :opacity, :openness, :oy, :padding, :padding_bottom, :tone, :visible, :width, :windowskin, :x, :y, :z\n"
      "  def open?\n"
      "    true\n"
      "  end\n"
      "  def update\n"
      "  end\n"
      "  def initialize(*args)\n"
      "    @cursor_rect = Rect.new(0, 0, 0, 0)\n"
      "    @contents = Bitmap.new(0, 0)\n"
      "    @oy = 0\n"
      "    @width = 0\n"
      "    @height = 0\n"
      "    @tone = Tone.new(0.0, 0.0, 0.0, 0.0)\n"
      "  end\n"
      "end\n"
      "\n"
      "module RPG\n"
      "  class Actor\n"
#if RGSS == 1
      "    attr_accessor :armor1_id, :armor2_id, :armor3_id, :armor4_id, :battler_hue, :battler_name, :character_hue, :character_name, :class_id, :initial_level, :exp_basis, :exp_inflation, :final_level, :name, :parameters, :weapon_id\n"
#endif
      "  end\n"
#if RGSS == 1
      "  class AudioFile\n"
      "    attr_accessor :name, :pitch, :volume\n"
      "  end\n"
#endif
      "  class Animation\n"
      "    class Frame\n"
      "    end\n"
      "    class Timing\n"
      "    end\n"
      "  end\n"
#if RGSS == 2
      "  class Area\n"
      "  end\n"
#endif
      "  class Armor\n"
#if RGSS == 1
      "    attr_accessor :auto_state_id\n"
#endif
      "  end\n"
#if RGSS >= 2
      "  class BGM\n"
      "    def play\n"
      "    end\n"
      "  end\n"
      "  class BGS\n"
      "    def self.stop\n"
      "    end\n"
      "  end\n"
#endif
#if RGSS == 3
      "  module BaseItem\n"
      "    class Feature\n"
      "    end\n"
      "  end\n"
#endif
#if RGSS == 1
      "  module Cache\n"
      /* TODO: RPG::Cache.title */
      "    def self.autotile(autotile_name)\n"
      "    end\n"
      "    def self.character(character_name, character_hue)\n"
      "    end\n"
      "    def self.title(title_name)\n"
      "    end\n"
      "    def self.tileset(tileset_name)\n"
      "    end\n"
      "    def self.windowskin(windowskin_name)\n"
      "    end\n"
      "  end\n"
#endif
      "  class Class\n"
#if RGSS == 1
      "    attr_accessor :learnings\n"
#endif
      "    class Learning\n"
#if RGSS == 1
      "      attr_accessor :level, :skill_id\n"
#endif
      "    end\n"
      "  end\n"
      "  class CommonEvent\n"
#if RGSS == 1
      "    attr_accessor :switch_id, :trigger\n"
#endif
      "  end\n"
      "  class Enemy\n"
      "    class Action\n"
      "    end\n"
#if RGSS >= 2
      "    class DropItem\n"
      "    end\n"
#endif
      "  end\n"
#if RGSS == 1
      "  class Event\n"
      "    attr_accessor :pages, :x, :y\n"
      "    class Page\n"
      "      attr_accessor :always_on_top, :condition, :direction_fix, :graphic, :list, :move_frequency, :move_route, :move_speed, :move_type, :step_anime, :through, :trigger, :walk_anime\n"
      "      class Condition\n"
      "        attr_accessor :self_switch_valid, :switch1_id, :switch1_valid, :switch2_valid, :variable_valid\n"
      "      end\n"
      "      class Graphic\n"
      "        attr_accessor :blend_type, :character_hue, :character_name, :direction, :opacity, :pattern, :tile_id\n"
      "      end\n"
      "    end\n"
      "  end\n"
#endif
      "  class EventCommand\n"
      "  end\n"
      "  class Item\n"
      "  end\n"
#if RGSS >= 2
      "  class ME\n"
      "    def self.stop\n"
      "    end\n"
      "  end\n"
#endif
#if RGSS == 1
      "  class Map\n"
      "    attr_accessor :autoplay_bgm, :autoplay_bgs, :data, :encounter_step, :events, :height, :tileset_id, :width\n"
      "  end\n"
#endif
      "  class MapInfo\n"
#if RGSS == 1
      "    attr_accessor :name\n"
#endif
      "  end\n"
      "  class MoveCommand\n"
      "  end\n"
      "  class MoveRoute\n"
      "  end\n"
#if RGSS >= 2
      "  class SE\n"
      "  end\n"
#endif
      "  class Skill\n"
      "  end\n"
#if RGSS == 1
      "  class Sprite < ::Sprite\n"
      "    @@_animations = []\n"
      "  end\n"
#endif
      "  class State\n"
      "  end\n"
      "  class System\n"
      "    attr_accessor :title_bgm\n"
#if RGSS >= 2
      "    attr_accessor :airship, :boat, :ship\n"
      "    attr_accessor :terms\n"
#endif
#if RGSS == 3
      "    attr_accessor :game_title, :opt_draw_title, :opt_followers, :opt_transparent, :opt_use_midi, :start_map_id, :title1_name, :title2_name, :window_tone\n"
#elif RGSS == 2
#elif RGSS == 1
      "    attr_accessor :party_members, :start_map_id, :start_x, :start_y, :title_name, :windowskin_name\n"
#endif
      "    class "TERMS"\n"
#if RGSS == 3
      "      attr_accessor :commands\n"
#elif RGSS == 2
      "      attr_accessor :continue, :gold, :new_game, :shutdown\n"
#elif RGSS == 1
#endif
      "    end\n"
      "    class TestBattler\n"
      "    end\n"
#if RGSS >= 2
      "    class Vehicle\n"
      "      attr_accessor :character_index, :character_name, :start_map_id, :start_x, :start_y\n"
#if RGSS == 3
#else
      "      attr_accessor :bgm\n"
#endif
      "    end\n"
#endif
      "  end\n"
#if RGSS == 1 || RGSS == 3
      "  class Tileset\n"
#if RGSS == 1
      "    attr_accessor :autotile_names, :battleback_name, :fog_blend_type, :fog_hue, :fog_name, :fog_opacity, :fog_sx, :fog_sy, :fog_zoom, :panorama_hue, :panorama_name, :passages, :priorities, :terrain_tags, :tileset_name\n"
#endif
      "  end\n"
#endif
      "  class Troop\n"
      "    class Member\n"
      "    end\n"
      "    class Page\n"
      "      class Condition\n"
      "      end\n"
      "    end\n"
      "  end\n"
#if RGSS == 3
      "  module UsableItem\n"
      "    class Effect\n"
      "    end\n"
      "    class Damage\n"
      "    end\n"
      "  end\n"
#endif
      "  class Weapon\n"
      "  end\n"
      "end\n"
      "\n"
#if RGSS == 3
      "def rgss_main\n"
      "  yield\n"
      "rescue "RGSS_RESET"\n"
      "  GC.start\n"
      "  retry\n"
      "end\n"
      "def rgss_stop\n"
      "  loop { Graphics.update }\n"
      "end\n"
      "def msgbox(*args)\n"
      "  print *args\n"
      "end\n"
      "def msgbox_p(*args)\n"
      "  p *args\n"
      "end\n"
#endif
      /* TODO: read from archive */
      "def load_data(filename)\n"
      "  File.open(filename.gsub(/\\\\/, \"/\"), \"rb\") do|f|\n"
      "    Marshal.load(f)\n"
      "  end\n"
      "end\n"
      "def save_data(obj, filename)\n"
      "  File.open(filename.gsub(/\\\\/, \"/\"), \"wb\") do|f|\n"
      "    Marshal.dump(obj, f)\n"
      "  end\n"
      "end\n"
      "begin\n"
      /* TODO: determine script path from Game.ini */
      "  load_data("SCRIPT_PATH").each do|num,title,script|\n"
      "    s = Zlib::Inflate::inflate(script)\n"
#if RGSS == 3
      "    s.force_encoding(\"utf-8\")\n"
#endif
      "    eval(s, binding, title)\n"
      "  end\n"
      "rescue "RGSS_RESET"\n"
      "  retry\n"
      // "rescue SystemExit\n"
      // "  raise\n"
      "rescue Exception => e\n"
      "  $stderr.print(\"#{e.class}: #{e.message}\\n\")\n"
      "  e.backtrace.each do|frame|\n"
      "    $stderr.print(\"\\tfrom #{frame}\\n\")\n"
      "  end\n"
      "end\n"
  );
  return Qnil;
}
