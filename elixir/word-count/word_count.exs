defmodule Words do
  @doc """
  Count the number of words in the sentence.

  Words are compared case-insensitively.
  """
  @spec count(String.t()) :: map
  def count(sentence) do
    sentence = String.downcase(sentence)
    words = String.split(String.replace(sentence, ~r/[,_\:\^&*%#$!@]/, " "))
    Enum.reduce(words, %{}, fn (w, acc) ->
      Map.put(acc, w, Map.get(acc, w, 0) + 1)
    end)
  end
end
